/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:21 by kannie            #+#    #+#             */
/*   Updated: 2022/05/07 13:45:22 by kannie           ###   ########.fr       */
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

void	ft_sleep(int time, t_philo *philo)
{
	long long	start_time;

	start_time = time_to();
	while ((time_to() - start_time) < (time / 1000))
	{
		philo->f_kill = check_pulse(philo);
		if (philo->f_kill > 0)
			break ;
		usleep(100);
	}
}

int	check_pulse(t_philo *philo)
{
	long long	time_to_die;

	time_to_die = time_to() - philo->start;
	if (time_to_die > (philo->waiter->time_to_die / 1000))
		philo->waiter->p_kill = 1;
	return (philo->waiter->p_kill);
}

int	check_dide(t_philo *philo, int print_time)
{
	philo->f_kill = check_pulse(philo);
	if (philo->f_kill > 0)
	{
		printf("%d %d:\033[0;31m died\e[0m\n", print_time, philo->id);
		return (1);
	}
	return (0);
}
