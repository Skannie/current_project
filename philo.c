/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:26 by kannie            #+#    #+#             */
/*   Updated: 2022/04/19 15:45:44 by kannie           ###   ########.fr       */
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

void	*function(void *buf)
{
	int				time;
	t_philo			*philo;

	philo = (t_philo *)buf;
	gettimeofday(&philo->current_time, NULL);
	philo->start = philo->current_time.tv_usec
		+ (philo->current_time.tv_sec * 1000000);
	usleep((philo->time_to_eat));
	usleep((philo->time_to_sleep));
	gettimeofday(&philo->current_time, NULL);
	philo->end = philo->current_time.tv_usec
		+ (philo->current_time.tv_sec * 1000000);
	time = (philo->end - philo->start) / 1000;
	if (philo->time_to_die >= time)
		printf("ok\n");
	else
		printf("philosopher -> die\n");
	printf("time-->%d\n", time);
	printf("Exit_proc\n");
	return (NULL);
}

void	even_philosophers(t_philo *philo)
{
	pthread_t	life_philo;

	printf("chetn\n");
	while (philo->number_of_philosophers > 0)
	{
		philo->number++;
		pthread_create(&life_philo, NULL, function, (void *)philo);
		pthread_detach(life_philo);
		philo->number_of_philosophers--;
	}
	pthread_join(life_philo, NULL);
	printf("Exit_philo\n");
}

void	odd_philosophers(void)
{
	printf("nechetn\n");
}

int	main(int argc, char *argv[])
{
	t_philo	philo;

	philo.i = 0;
	if (argc == 5)
	{
		philo.number = 0;
		philo.number_of_philosophers = ft_atoi(argv[1]);
		if (philo.number_of_philosophers < 2)
			return (-1);
		philo.time_to_die = ft_atoi(argv[2]) * 1000;
		philo.time_to_eat = ft_atoi(argv[3]) * 1000;
		philo.time_to_sleep = ft_atoi(argv[4]) * 1000;
		if (philo.number_of_philosophers % 2 == 0)
			even_philosophers(&philo);
		else
			odd_philosophers();
		return (0);
	}
	else
		return (-1);
}
