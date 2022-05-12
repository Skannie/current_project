/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:18 by kannie            #+#    #+#             */
/*   Updated: 2022/05/07 16:26:31 by kannie           ###   ########.fr       */
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
	philo->start = time_to();
	while (philo->f_kill == 0 && philo->waiter->p_kill == 0)
	{
		if (philo->must_eat == 0)
		{
			philo->waiter->must_eat--;
			break ;
		}
		philo->f_kill = life(philo, time);
		if (philo->f_kill > 0)
			break ;
	}
	return (NULL);
}

int	life(t_philo *philo, long long time)
{
	philo->f_kill = what_philo_do(philo, time, "36m is thinking", 0);
	lock_fork(philo);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	philo->f_kill = what_philo_do(philo, time, "32m has taken a forks", 0);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	philo->start = time_to();
	philo->f_kill = what_philo_do(philo, time, "35m is eating",
			philo->time_to_eat);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	if (philo->must_eat > 0)
		philo->must_eat--;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->f_kill = what_philo_do(philo, time, "34m is sleeping",
			philo->time_to_sleep);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	usleep(100);
	return (philo->f_kill);
}

int	what_philo_do(t_philo *philo, long long time, char *str, int time_to_do)
{
	int	print_time;
	int	i;

	i = 0;
	print_time = time_to() - time;
	pthread_mutex_lock(philo->print_mutx);
	printf("%d %d:\033[0;%s\e[0m\n", print_time, philo->id, str);
	pthread_mutex_unlock(philo->print_mutx);
	i = check_dide(philo, print_time);
	if (time_to_do > 0 && philo->f_kill == 0)
		ft_sleep(time_to_do, philo);
	return (i);
}
