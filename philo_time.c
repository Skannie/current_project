/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:21 by kannie            #+#    #+#             */
/*   Updated: 2022/05/17 21:05:04 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_to(void)
{
	long long		time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_usec / 1000) + (current_time.tv_sec * 1000);
	return (time);
}

void	ft_sleep(int time, t_philo *philo, int eat)
{
	long long	start_time;

	start_time = time_to();
	while ((time_to() - start_time) < (time / 1000))
	{
		if (eat == 0)
			check_pulse(philo);
		if (philo->f_kill > 0 && philo->waiter->p_kill > 0)
			break ;
		usleep(100);
	}
}

void	check_pulse(t_philo *philo)
{
	long long	time_to_die;

	time_to_die = time_to() - philo->start;
	if (time_to_die > (philo->waiter->time_to_die / 1000))
	{
		pthread_mutex_lock(philo->print_mutx);
		philo->f_kill = 1;
		philo->waiter->p_kill = 1;
		pthread_mutex_unlock(philo->print_mutx);
	}
}

void	check_dide(t_philo *philo, int print_time)
{
	check_pulse(philo);
	if (philo->f_kill > 0)
		printf("%d %d:\033[0;31m died\e[0m\n", print_time, philo->id);
}
