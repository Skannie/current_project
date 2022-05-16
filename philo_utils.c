/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:59:01 by kannie            #+#    #+#             */
/*   Updated: 2022/05/16 19:25:46 by kannie           ###   ########.fr       */
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

int	num_portion(char *str, t_waiter *waiter)
{
	int	i;

	i = -1;
	waiter->must_eat = ft_atoi(str);
	if (waiter->must_eat <= 0)
		return (-1);
	waiter->num_eat = malloc (sizeof (int) * waiter->number_philo);
	if (!waiter->num_eat)
		return (-1);
	while (++i < waiter->number_philo)
		waiter->num_eat[i] = 0;
	return (0);
}

int	philo_eat(t_philo *philo, long long time, char *str)
{
	int	print_time;
	int	i;

	i = 0;
	print_time = time_to() - time;
	pthread_mutex_lock(philo->print_mutx);
	printf("%d %d:\033[0;%s\e[0m\n", print_time, philo->id, str);
	pthread_mutex_unlock(philo->print_mutx);
	if (philo->f_kill == 0)
		ft_sleep(philo->time_to_eat, philo, 1);
	if (philo->must_eat > 0)
	{
		pthread_mutex_lock(philo->print_mutx);
		philo->waiter->num_eat[(philo->id - 1)]++;
		pthread_mutex_unlock(philo->print_mutx);
	}
	return (i);
}

int	f_waiter(t_waiter *waiter)
{
	int	i;
	int	num_ate;

	i = 0;
	num_ate = 0;
	while (waiter->number_philo > i)
	{
		if (waiter->num_eat[i] >= waiter->must_eat)
			num_ate++;
		i++;
	}
	if (num_ate == waiter->number_philo)
		return (1);
	return (0);
}
