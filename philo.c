/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:26 by kannie            #+#    #+#             */
/*   Updated: 2022/04/08 17:04:54 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;

	philo.i = 0;
	if (argc == 5)
	{
		philo.number = ft_atoi(argv[1]);
		philo.time_life = ft_atoi(argv[2]);
		philo.time_eat = ft_atoi(argv[3]);
		philo.time_sleep = ft_atoi(argv[4]);
	}
	else
		return (0);
}
