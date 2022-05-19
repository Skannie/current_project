/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:07:18 by kannie            #+#    #+#             */
/*   Updated: 2022/05/19 19:52:40 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_waiter *waiter)
{
	t_philo			*philo;
	int				i;

	i = -1;
	philo = malloc (sizeof(t_philo) * waiter->nbr_philo);
	if (!philo)
		return (-1);
	waiter->start = time_to();
	while (waiter->nbr_philo > ++i)
	{
		values_philo(waiter, &(philo[i]), i);
		pthread_create(&philo[i].life_philo, NULL, &philo_life, (&philo[i]));
	}
	waiter_philo(waiter);
	i = -1;
	while (waiter->nbr_philo > ++i)
		pthread_join(philo[i].life_philo, NULL);
	return (0);
}

void	*philo_life(void *buf)
{
	t_philo		*philo;

	philo = (t_philo *)buf;
	while (1)
	{
		pthread_mutex_lock(philo->print_mutx);
		if (philo->waiter->sig_eat > 0 || philo->waiter->p_kill > 0)
			break ;
		pthread_mutex_unlock(philo->print_mutx);
		f_life(philo);
	}
	pthread_mutex_unlock(philo->print_mutx);
	return (NULL);
}

void	f_life(t_philo *philo)
{
	if (check_dide(philo) == 1)
	{
		pthread_mutex_unlock(philo->print_mutx);
		return ;
	}
	what_philo_do(philo, "36m is thinking", 0);
	lock_fork(philo);
	pthread_mutex_unlock(philo->print_mutx);
	philo->last_eat = time_to();
	what_philo_do(philo, "35m is eating", philo->time_to_eat);
	if (philo->must_eat > 0)
	{
		pthread_mutex_lock(philo->lock_mu);
		(philo->waiter->num_eat[(philo->id - 1)])++;
		pthread_mutex_unlock(philo->lock_mu);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	what_philo_do(philo, "34m is sleeping", philo->time_to_sleep);
}

void	what_philo_do(t_philo *philo, char *str, int time_to_do)
{
	if (check_dide(philo) == 1)
	{
		unlock_fork(philo);
		return ;
	}
	pthread_mutex_lock(philo->print_mutx);
	printf("%lld %d\033[0;%s\e[0m\n", (time_to() - philo->start), philo->id, str);
	pthread_mutex_unlock(philo->print_mutx);
	if (time_to_do > 0)
		ft_sleep((time_to_do / 1000), philo);
	check_dide(philo);
}
