/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:09:41 by kannie            #+#    #+#             */
/*   Updated: 2022/05/12 16:18:18 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	values_waiter(char *str[], t_waiter *waiter)
{
	waiter->number_philo = ft_atoi(str[1]);
	if (waiter->number_philo < 2)
		return (-1);
	waiter->time_to_die = ft_atoi(str[2]) * 1000;
	if (waiter->time_to_die < 1)
		return (-1);
	waiter->time_to_eat = ft_atoi(str[3]) * 1000;
	if (waiter->time_to_eat < 1)
		return (-1);
	waiter->time_to_sleep = ft_atoi(str[4]) * 1000;
	if (waiter->time_to_sleep < 1)
		return (-1);
	if (str[5])
		waiter->must_eat = ft_atoi(str[5]);
	if (waiter->must_eat < 0)
		return (-1);
	if (!(str[5]))
		waiter->must_eat = -1;
	waiter->forks = malloc (sizeof(pthread_mutex_t) * waiter->number_philo);
	if (!waiter->forks)
		return (-1);
	init_forks(waiter);
	return (0);
}

void	values_philo(t_waiter *waiter, t_philo *philo)
{
	philo->time_to_eat = waiter->time_to_eat;
	philo->time_to_sleep = waiter->time_to_sleep;
	philo->f_kill = waiter->p_kill;
	if (!(waiter->must_eat))
		philo->must_eat = -1;
	else
		philo->must_eat = waiter->must_eat;
}

void	init_forks(t_waiter *waiter)
{
	int	i;

	i = -1;
	while (++i < waiter->number_philo)
		pthread_mutex_init(&waiter->forks[i], NULL);
	pthread_mutex_init(&waiter->print_mutx, NULL);
}

// while ()
// 			pthread_mutex_destroy(waiter.forks[i]);
// 		pthread_mutex_destroy(waiter.print_mutx);