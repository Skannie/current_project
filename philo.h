/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:35:29 by kannie            #+#    #+#             */
/*   Updated: 2022/04/08 17:03:17 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int	i;
	int	number;
	int	time_life;
	int	time_eat;
	int	time_sleep;
}	t_philo;

int		ft_atoi(const char *str);
int		schar_v_int(const char *strok, int i, int minus);

#endif