/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:21 by kannie            #+#    #+#             */
/*   Updated: 2022/04/28 15:46:28 by kannie           ###   ########.fr       */
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

void	ft_usleep(int time)
{
	long long	start_time;

	start_time = time_to();
	while ((time_to() - start_time) < (time / 1000))
		usleep(100);
}

int	check_pulse(t_waiter waiter)
{
	int	time_to_die;

	time_to_die = time_to() - waiter.start;
	if (time_to_die >= waiter.time_to_die)
		waiter.p_kill = 1;
	return (waiter.p_kill);
}
