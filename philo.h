/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:35:29 by kannie            #+#    #+#             */
/*   Updated: 2022/04/25 16:32:55 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	mutex;
	int				p_kill;
	int				number_philosopher_must_eat;
	int				number_of_philosophers;
	int				number_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start;
	long			end;
	struct timeval	current_time;
}	t_philo;

typedef struct s_flow
{
	t_philo		*philo;
	pthread_t	life_philo;
	int			id;
	int			number_philosopher_must_eat;
	int			number_of_forks;
	int			time_to_eat;
	int			time_to_sleep;
	int			f_kill;
}	t_flow;

int		ft_atoi(const char *str);
int		schar_v_int(const char *strok, int i, int minus);

#endif