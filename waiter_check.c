/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:55:46 by kannie            #+#    #+#             */
/*   Updated: 2022/05/22 18:55:20 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	waiter_check_eat(t_waiter *waiter)
{
	int	i;
	int	num_ate;

	i = 0;
	num_ate = 0;
	while (i < waiter->nbr_philo)
	{
		pthread_mutex_lock(&waiter->print_mutx);
		if (waiter->must_eat <= waiter->philo[i].nbr_eat)
			num_ate++;
		pthread_mutex_unlock(&waiter->print_mutx);
		i++;
	}
	if (num_ate == waiter->nbr_philo)
		waiter->sig_eat = 1;
}

void	waiter_check_die(t_waiter *waiter)
{
	int	i;
	int	num_ate;

	i = 0;
	num_ate = 0;
	while (i < waiter->nbr_philo)
	{
		pthread_mutex_lock(&waiter->print_mutx);
		// printf("%d lust_eat-> %lld time_to_die-> %d\n", (i + 1), (time_to() - waiter->philo[i].last_eat), waiter->time_to_die);	
		if ((time_to() - waiter->philo[i].last_eat) > waiter->time_to_die)
		{
			printf("%d lust_eat-> %lld time_to_die-> %d\n", (i + 1), (time_to() - waiter->philo[i].last_eat), waiter->time_to_die);	
			waiter->s_die = 1;
		}
		pthread_mutex_unlock(&waiter->print_mutx);
		if (waiter->s_die == 1)
		{
			pthread_mutex_lock(&waiter->print_mutx);
			waiter->philo[i].f_kill = 1;
			pthread_mutex_unlock(&waiter->print_mutx);
			break ;
		}
		i++;
	}
}

void	waiter_philo(t_waiter *waiter)
{
	while (1)
	{
		if (waiter->must_eat > 0)
			waiter_check_eat(waiter);
		if (waiter->sig_eat == 0)
			waiter_check_die(waiter);
		if (waiter->sig_eat == 1 || waiter->s_die == 1)
		{
			printf("sig_eat = %d s_die = %d\n", waiter->sig_eat, waiter->s_die);
			break ;
		}
	}
}
