/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:35:29 by kannie            #+#    #+#             */
/*   Updated: 2022/05/17 21:07:27 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_waiter
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*lock_mu;
	pthread_mutex_t	print_mutx;
	int				p_kill;
	int				sig_eat;
	int				must_eat;
	int				*num_eat;
	int				number_philo;
	int				number_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				info;
}	t_waiter;

typedef struct s_philo
{
	t_waiter		*waiter;
	pthread_t		life_philo;
	int				must_eat;
	long long		start;
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				f_kill;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutx;
	pthread_mutex_t	*lock_mu;
}	t_philo;

int			ft_atoi(const char *str);
int			schar_v_int(const char *strok, int i, int minus);
int			create_philo(t_waiter *waiter);
void		init_forks(t_waiter *waiter);
void		*philo_life(void *buf);
int			values_waiter(char *str[], t_waiter *waiter);
int			num_portion(char *str, t_waiter *waiter);
void		values_philo(t_waiter *waiter, t_philo *philo, int i);
void		*philo_life(void *buf);
long long	time_to(void);
void		what_philo_do(t_philo *philo, long long time, char *str,
				int time_to_do);
void		philo_eat(t_philo *philo, long long time, char *str);
void		lock_fork(t_philo *philo);
int			print_exit(int i);
void		ft_sleep(int time, t_philo *philo, int eat);
void		check_pulse(t_philo *philo);
void		check_dide(t_philo *philo, int print_time);
int			life(t_philo *philo, long long time);
int			f_waiter(t_waiter *waiter);
void		signal_ate(int i, int id, t_waiter *waiter);

#endif