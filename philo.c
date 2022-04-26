/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:26 by kannie            #+#    #+#             */
/*   Updated: 2022/04/26 14:44:51 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_t	mutex; - создание переменную мьютекс
// pthread_mutex_init(&mutex, NULL); - инициализация мьютекс
// pthread_mutex_destroy(&mutex); - уничтожение мьютекс
// pthread_mutex_lock(&mutex); - блокировка мьютексом
// pthread_mutex_unlock(&mutex); - разблокировка мьютексом
// pthread_create(&s1, NULL, print, (void *)b); - создаёт параллельный процесс
// pthread_detach(s1); - не ждёт завершения потока s1 и идёт дальше
// pthread_join(s1, NULL); - ждёт завершения потока s1 после чего идёт дальше
// usleep(100000); - команда говорит ждать в течении N времени (в микросекудах)
// void	*print(void *param)

// waiter->end = waiter->current_time.tv_usec 
// + (waiter->current_time.tv_sec * 1000000);
// time = (waiter->end - waiter->start) / 1000;

// Написать массив структур чтобы можно было передавать каждому философу
// свои значения, для этого надо будте выделить память маллоком.
// Сделать так чтобы функция определения смерти была в самом мейнике и
// эту функцию надо отправлять непосредсвенно в каждый поток,
// чтобы она смотрела умер ли философ.
// Как смотреть умер ли философ - надо запомнить время когда я зохожу в функцию
// определения смерти философа, смотреть когда в последний раз ел философ
// относительно времени когда я зашёл в функцию ревизорро.

long long	time_to(void)
{
	long long		time;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL); // начало отчёта времени до смерти
	time = (current_time.tv_usec / 1000)
		+ (current_time.tv_sec * 1000);
	return (time);
}

void	*philo_life(void *buf)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)buf;
	time = time_to();
	while (philo->f_kill == 0)
	{
		printf("\033[0;32m%lld %d: is thinking\e[0m\n", (time_to() - time), philo->id);
		if (philo->id % 2)
		{
			pthread_mutex_lock(philo->right_fork);
			pthread_mutex_lock(philo->left_fork);
		}
		if (!(philo->id % 2))
		{
			pthread_mutex_lock(philo->left_fork);
			pthread_mutex_lock(philo->right_fork);
		}
		// print_mu();
		printf("\033[0;33m%lld %d: has taken a forks\e[0m\n", (time_to()
					- time), philo->id);
		printf("\033[0;31m%lld %d: eat\e[0m\n", (time_to() - time), philo->id);
		usleep((philo->time_to_eat));
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("\033[0;34m%lld %d: sleep\e[0m\n", (time_to() - time), philo->id);
		usleep(philo->time_to_sleep);
	}
	return (NULL);
}

void	values_philo(t_waiter *waiter, t_philo *philo)
{
	philo->time_to_eat = waiter->time_to_eat;
	philo->time_to_sleep = waiter->time_to_sleep;
	philo->f_kill = waiter->p_kill;
	if (waiter->must_eat)
		philo->must_eat = waiter->must_eat;
}

int	create_philo(t_waiter *waiter)
{
	t_philo			*philo;
	int				i;

	i = -1;
	philo = malloc (sizeof(t_philo) * waiter->number_philo);
	if (!philo)
		return (-1);
	while (waiter->number_philo > ++i)
	{
		philo[i].id = i + 1;
		values_philo(waiter, &(philo[i]));
		philo[i].left_fork = &waiter->forks[i];
		if (philo[i].id == waiter->number_philo)
			philo[i].right_fork = &waiter->forks[0];
		else
			philo[i].right_fork = &waiter->forks[i + 1];
		pthread_create(&philo[i].life_philo, NULL, &philo_life, (&philo[i]));
	}
	return (0);
}

int	error_exit(int i)
{
	printf("Error");
	return (i);
}

void	init_forks(t_waiter *waiter)
{
	int	i;

	i = -1;
	while (++i < waiter->number_philo)
		pthread_mutex_init(&waiter->forks[i], NULL);
}

int	values_waiter(char *str[], t_waiter *waiter)
{
	int	i;

	i = 0;
	waiter->number_philo = ft_atoi(str[1]);
	if (waiter->number_philo < 2)
		i = 1;
	waiter->forks = malloc (sizeof(pthread_mutex_t) * waiter->number_philo);
	if (!waiter->forks)
		return (1);
	waiter->time_to_die = ft_atoi(str[2]) * 1000;
	if (waiter->time_to_die < 1)
		i = 1;
	init_forks(waiter);
	waiter->time_to_eat = ft_atoi(str[3]) * 1000;
	if (waiter->time_to_die < 1)
		i = 1;
	waiter->time_to_sleep = ft_atoi(str[4]) * 1000;
	if (waiter->time_to_die < 1)
		i = 1;
	if (str[5])
		waiter->must_eat = ft_atoi(str[5]);
	if (waiter->must_eat < 0)
		i = 1;
	waiter->start = time_to();
	return (i);
}

int	main(int argc, char **argv)
{
	t_waiter	waiter;
	int			i;

	i = 0;
	waiter.must_eat = 0;
	waiter.p_kill = 0;
	if (argc >= 5 && argc <= 6)
	{
		i = values_waiter(argv, &waiter);
		if (i == 1)
			return (error_exit(i));
		i = create_philo(&waiter);
		if (i == 1)
			return (error_exit(i));
		while (waiter.p_kill == 0)
			continue ;
		printf("Exit_waiter\n");
		return (0);
	}
	else
		return (1);
}
