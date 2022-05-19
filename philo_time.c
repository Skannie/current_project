/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:21 by kannie            #+#    #+#             */
/*   Updated: 2022/05/19 19:57:40 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to(void)
{
	struct timeval	tm;
	long long		time;

	gettimeofday(&tm, NULL);
	time = (tm.tv_sec * 1000 + tm.tv_usec / 1000);
	return (time);
}

void	ft_sleep(long long time_do, t_philo *philo)
{
	long long	time_now;

	time_now = time_to();
	while (time_do > (time_to() - time_now))
	{
		check_dide(philo);
		pthread_mutex_lock(philo->print_mutx);
		if (philo->waiter->s_die > 0)
			break ;
		pthread_mutex_unlock(philo->print_mutx);
		usleep(100);
	}
	pthread_mutex_unlock(philo->print_mutx);
}

int	check_dide(t_philo *philo)
{
	long long	time_to_life;

	pthread_mutex_lock(philo->print_mutx);
	if (philo->waiter->p_kill[philo->id - 1] > 0)
		return (1);
	pthread_mutex_unlock(philo->print_mutx);
	pthread_mutex_lock(philo->lock_mu);
	time_to_life = time_to() - philo->last_eat;
	if (time_to_life > (philo->waiter->time_to_die / 1000))
		philo->waiter->p_kill[philo->id - 1] = 1;
	pthread_mutex_unlock(philo->lock_mu);
	return (0);
}
