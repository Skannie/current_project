/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:18 by kannie            #+#    #+#             */
/*   Updated: 2022/04/28 17:30:24 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_waiter *waiter)
{
	t_philo			*philo;
	int				i;

	i = -1;
	philo = malloc (sizeof(t_philo) * waiter->number_philo);
	if (!philo)
		return (-1);
	while (waiter->number_philo > ++i)
	{
		philo[i].id = i + 1;
		values_philo(waiter, &(philo[i]));
		philo[i].print_mutx = &waiter->print_mutx;
		philo[i].left_fork = &waiter->forks[i];
		philo[i].waiter = waiter;
		if (philo[i].id == waiter->number_philo)
			philo[i].right_fork = &waiter->forks[0];
		else
			philo[i].right_fork = &waiter->forks[i + 1];
		pthread_create(&philo[i].life_philo, NULL, &philo_life, (&philo[i]));
	}
	return (0);
}

void	init_forks(t_waiter *waiter)
{
	int	i;

	i = -1;
	while (++i < waiter->number_philo)
		pthread_mutex_init(&waiter->forks[i], NULL);
	pthread_mutex_init(&waiter->print_mutx, NULL);
}

void	lock_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
}

void	*philo_life(void *buf)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)buf;
	time = time_to();
	philo->waiter->start = time;
	while (philo->f_kill == 0 && philo->waiter->p_kill == 0)
	{
		philo->f_kill = what_philo_do(philo, time, "36m is thinking", 0);
		lock_fork(philo);
		philo->f_kill = what_philo_do(philo, time, "32m has taken a forks", 0);
		philo->f_kill = what_philo_do(philo, time, "33m is eating",
				philo->time_to_eat);
		philo->waiter->start = time_to();
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->f_kill = what_philo_do(philo, time, "34m is sleeping",
				philo->time_to_sleep);
	}
	return (NULL);
}

int	what_philo_do(t_philo *philo, long long time, char *str, int time_to_do)
{
	int	print_time;

	print_time = time_to() - time;
	pthread_mutex_lock(philo->print_mutx);
	printf("%d %d:\033[0;%s\e[0m\n", print_time, philo->id, str);
	pthread_mutex_unlock(philo->print_mutx);
	if (time_to_do > 0)
	{
		philo->f_kill = check_pulse(philo->waiter);
		if (philo->f_kill > 0)
		{
			printf("%d %d:\033[0;31m died\e[0m\n", print_time, philo->id);
			return (1);
		}
		ft_sleep(time_to_do);
		philo->f_kill = check_pulse(philo->waiter);
		if (philo->f_kill > 0)
		{
			printf("%d %d:\033[0;31m died\e[0m\n", print_time, philo->id);
			return (1);
		}
	}
	return (0);
}
