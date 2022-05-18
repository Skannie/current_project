/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:21 by kannie            #+#    #+#             */
/*   Updated: 2022/05/18 21:44:20 by kannie           ###   ########.fr       */
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
		check_pulse(philo);
		if (philo->f_kill > 0 && philo->waiter->p_kill > 0)
			break ;
		usleep(100);
	}
}

void	check_pulse(t_philo *philo)
{
	long long	time_to_die;

	time_to_die = time_to() - philo->last_eat;
	if (time_to_die > (philo->waiter->time_to_die / 1000))
	{
		pthread_mutex_lock(philo->print_mutx);
		philo->f_kill = 1;
		philo->waiter->p_kill = 1;
		pthread_mutex_unlock(philo->print_mutx);
	}
}

void	check_dide(t_philo *philo)
{
	check_pulse(philo);
	if (philo->f_kill > 0)
		printf("%lld %d\033[0;31m died\e[0m\n", (time_to() - philo->start),
			philo->id);
}
