/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:55:46 by kannie            #+#    #+#             */
/*   Updated: 2022/05/21 00:16:47 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	waiter_check_eat(t_waiter *waiter)
{
	int	i;
	int	num_ate;

	i = 0;
	num_ate = 0;
	while (i < waiter->nbr_philo)
	{
		pthread_mutex_lock(&waiter->print_mutx);
		if (waiter->must_eat >= waiter->philo[i].nbr_eat)
			num_ate++;
		pthread_mutex_unlock(&waiter->print_mutx);
		i++;
	}
	if (num_ate == waiter->nbr_philo)
		return (1);
	return (0);
}

int	waiter_check_die(t_waiter *waiter)
{
	int	i;

	i = 0;
	while (i < waiter->nbr_philo)
	{
		pthread_mutex_lock(&waiter->print_mutx);
		if ((time_to() - waiter->philo[i].last_eat) > waiter->time_to_die)
			waiter->s_die = 1;
		pthread_mutex_unlock(&waiter->print_mutx);
		if (waiter->s_die == 1)
		{
			pthread_mutex_lock(&waiter->print_mutx);
			printf("%lld %d\033[0;31m died\e[0m\n", (time_to() - waiter->start),
				(i + 1));
			pthread_mutex_unlock(&waiter->print_mutx);
		}
		pthread_mutex_lock(&waiter->print_mutx);
		waiter->philo[i].f_kill = 1;
		pthread_mutex_unlock(&waiter->print_mutx);
		i++;
	}
	if (waiter->s_die == 1)
		return (1);
	return (0);
}

void	waiter_philo(t_waiter *waiter)
{
	while (1)
	{
		if (waiter->must_eat > 0 && waiter_check_eat(waiter) > 0)
			waiter->sig_eat = 1;
		if (waiter->sig_eat == 1 || waiter->s_die == 1)
			break ;
	}
}
