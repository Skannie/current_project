/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:59:01 by kannie            #+#    #+#             */
/*   Updated: 2022/05/19 19:40:42 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	schar_v_int(const char *strok, int i, int minus)
{
	unsigned int	l;

	l = 0;
	while (strok[i] >= 48 && strok[i] <= 57)
	{
		l = l * 10 + (strok[i] - 48);
		i++;
		if (l > 2147483647 && minus == 1)
			return (-1);
		if (l > 2147483648 && minus == -1)
			return (0);
	}
	return (l * minus);
}

int	ft_atoi(const char *str)
{
	int				a;
	int				minus;
	unsigned int	b;

	a = 0;
	b = 0;
	minus = 1;
	while (str[a] == ' ' || str[a] == '\n' || str[a] == '\t'
		|| str[a] == '\v' || str[a] == '\r' || str[a] == '\f')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-' && str[a + 1] != '-')
			minus = -1;
		else if (str[a] == '+' && str[a + 1] != '+')
			minus = 1;
		a++;
	}
	if (str[a] >= '0' && str[a] <= '9')
	{
		b = schar_v_int(str, a, minus);
		return (b);
	}
	else
		return (-1);
}

void	lock_fork(t_philo *philo)
{
	int	i;

	i = philo->id;
	if ((i % 2) == 0)
	{
		if (check_dide(philo) == 1)
			return ;
		pthread_mutex_lock(philo->right_fork);
		what_philo_do(philo, "32m has taken a  fork", 0);
		pthread_mutex_lock(philo->left_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
	}
	else
	{
		if (check_dide(philo) == 1)
			return ;
		pthread_mutex_lock(philo->left_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
		pthread_mutex_lock(philo->right_fork);
		what_philo_do(philo, "32m has taken a fork", 0);
	}
}

void	unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return ;
}
