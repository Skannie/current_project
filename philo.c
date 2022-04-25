/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:26 by kannie            #+#    #+#             */
/*   Updated: 2022/04/25 16:35:56 by kannie           ###   ########.fr       */
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

// philo->end = philo->current_time.tv_usec 
// + (philo->current_time.tv_sec * 1000000);
// time = (philo->end - philo->start) / 1000;

// Написать массив структур чтобы можно было передавать каждому философу
// свои значения, для этого надо будте выделить память маллоком.
// Сделать так чтобы функция определения смерти была в самом мейнике и
// эту функцию надо отправлять непосредсвенно в каждый поток,
// чтобы она смотрела умер ли философ.
// Как смотреть умер ли философ - надо запомнить время когда я зохожу в функцию
// определения смерти философа, смотреть когда в последний раз ел философ
// относительно времени когда я зашёл в функцию ревизорро.

// int	time_to(t_philo *philo)
// {
// 	int	time;

// 	gettimeofday(&philo->current_time, NULL); // начало отчёта времени до смерти
// 	time = philo->current_time.tv_usec
// 		+ (philo->current_time.tv_sec * 1000000);
// 	return (time);
// }

void	*function(void *buf)
{
	t_flow			*flow;

	flow = (t_flow *)buf;
	printf("%d\n", flow->id);
	while (flow->f_kill == 0)
	{
		usleep((flow->time_to_eat));
		printf("philo %d: eat\n", flow->id);
		usleep(flow->time_to_sleep);
		printf("philo %d: sleep\n", flow->id);
	}
	return (NULL);
}

void	valuse_filo(t_philo *philo, t_flow *flow)
{
	flow->time_to_eat = philo->time_to_eat;
	flow->time_to_sleep = philo->time_to_sleep;
	flow->f_kill = philo->p_kill;
	if (philo->number_philosopher_must_eat)
		flow->number_philosopher_must_eat = philo->number_philosopher_must_eat;
}

int	creat_philo(t_philo *philo)
{
	t_flow	*flow;
	int		i;

	i = -1;
	flow = malloc (sizeof(t_flow) * philo->number_of_philosophers);
	if (!flow)
		return (-1);
	while (philo->number_of_philosophers > ++i)
	{
		flow[i].id = i + 1;
		valuse_filo(philo, &(flow[i]));
		pthread_create(&flow->life_philo, NULL, function, (&flow[i]));
		pthread_detach(flow->life_philo);
	}
	usleep(10000);
	return (0);
}

int	error_exit(int i)
{
	printf("Error");
	return (i);
}

int	values_waiter(char *str[], t_philo *philo)
{
	int	i;

	i = 0;
	philo->number_of_philosophers = ft_atoi(str[1]);
	if (philo->number_of_philosophers < 2)
		i = 1;
	philo->time_to_die = ft_atoi(str[2]) * 1000;
	if (philo->time_to_die < 1)
		i = 1;
	philo->time_to_eat = ft_atoi(str[3]) * 1000;
	if (philo->time_to_die < 1)
		i = 1;
	philo->time_to_sleep = ft_atoi(str[4]) * 1000;
	if (philo->time_to_die < 1)
		i = 1;
	if (str[5])
		philo->number_philosopher_must_eat = ft_atoi(str[5]);
	if (philo->number_philosopher_must_eat < 0)
		i = 1;
	return (i);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	int		i;

	i = 0;
	philo.number_philosopher_must_eat = 0;
	philo.p_kill = 0;
	if (argc >= 5 && argc <= 6)
	{
		i = values_waiter(argv, &philo);
		if (i == 1)
			return (error_exit(i));
		i = creat_philo(&philo);
		if (i == 1)
			return (error_exit(i));
		while (philo.p_kill == 0)
			pause();
		printf("Exit_philo\n");
		return (0);
	}
	else
		return (1);
}
