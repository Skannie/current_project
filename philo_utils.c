/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:59:01 by kannie            #+#    #+#             */
/*   Updated: 2022/05/18 18:54:23 by kannie           ###   ########.fr       */
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

void	philo_eat(t_philo *philo, char *str)
{
	long long	time;

	time = time_to() - philo->start;
	pthread_mutex_lock(philo->print_mutx);
	printf("%lld %d\033[0;%s\e[0m\n", time, philo->id, str);
	pthread_mutex_unlock(philo->print_mutx);
	if (philo->f_kill == 0)
		ft_sleep((philo->time_to_eat / 1000), philo, 1);
	if (philo->must_eat > 0)
	{
		pthread_mutex_lock(philo->lock_mu);
		(philo->waiter->num_eat[(philo->id - 1)])++;
		pthread_mutex_unlock(philo->lock_mu);
	}
}

int	waiter_check_eat(t_waiter *waiter)
{
	int	i;
	int	num_ate;

	i = 0;
	num_ate = 0;
	while (waiter->number_philo > i)
	{
		pthread_mutex_lock(&waiter->lock_mu[i]);
		if (waiter->num_eat[i] >= waiter->must_eat)
			num_ate++;
		pthread_mutex_unlock(&waiter->lock_mu[i]);
		i++;
	}
	if (num_ate == waiter->number_philo)
		return (1);
	return (0);
}

void	waiter_philo(t_waiter *waiter)
{
	while (1)
	{
		if (waiter->must_eat > 0 && waiter_check_eat(waiter) > 0)
			waiter->sig_eat = 1;
		pthread_mutex_lock(&waiter->print_mutx);
		if (waiter->sig_eat == 1 || waiter->p_kill == 1 || waiter->sig_eat == 1)
			break ;
		pthread_mutex_unlock(&waiter->print_mutx);
	}
	pthread_mutex_unlock(&waiter->print_mutx);
}
