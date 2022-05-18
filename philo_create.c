/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:18 by kannie            #+#    #+#             */
/*   Updated: 2022/05/18 21:45:21 by kannie           ###   ########.fr       */
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
		values_philo(waiter, &(philo[i]), i);
		pthread_create(&philo[i].life_philo, NULL, &philo_life, (&philo[i]));
	}
	waiter_philo(waiter);
	i = -1;
	while (waiter->number_philo > ++i)
		pthread_join(philo[i].life_philo, NULL);
	return (0);
}

void	lock_fork(t_philo *philo)
{
	if ((philo->id % 2) == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
		pthread_mutex_lock(philo->right_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
		pthread_mutex_lock(philo->left_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
	}
}

void	*philo_life(void *buf)
{
	t_philo		*philo;

	philo = (t_philo *)buf;
	while (1)
	{
		pthread_mutex_lock(philo->print_mutx);
		if (philo->waiter->sig_eat > 0 || philo->f_kill > 0
			|| philo->waiter->p_kill > 0)
			break ;
		pthread_mutex_unlock(philo->print_mutx);
		philo->f_kill = f_life(philo);
	}
	pthread_mutex_unlock(philo->print_mutx);
	return (NULL);
}

int	f_life(t_philo *philo)
{
	what_philo_do(philo, "36m is thinking", 0);
	lock_fork(philo);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	philo_eat(philo, "35m is eating");
	if (philo->f_kill > 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (philo->f_kill);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	what_philo_do(philo, "34m is sleeping", philo->time_to_sleep);
	if (philo->f_kill > 0)
		return (philo->f_kill);
	usleep(100);
	return (philo->f_kill);
}

void	what_philo_do(t_philo *philo, char *str, int time_to_do)
{
	pthread_mutex_lock(philo->print_mutx);
	printf("%lld %d\033[0;%s\e[0m\n", (time_to() - philo->start), philo->id, str);
	pthread_mutex_unlock(philo->print_mutx);
	check_dide(philo);
	if (time_to_do > 0 && philo->f_kill == 0)
		ft_sleep((time_to_do / 1000), philo);
	check_dide(philo);
}
