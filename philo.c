/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:26 by kannie            #+#    #+#             */
/*   Updated: 2022/04/21 18:48:29 by kannie           ###   ########.fr       */
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

// void	*function(void *buf)
// {
// 	int				time;
// 	t_philo			*philo;
// 	int				i;

// 	i = 1;
// 	philo = (t_philo *)buf;
// 	while (philo->i == 0)
// 	{
// 		printf("philo %d: ", philo->number);
// 		philo->start = time_to(philo);
// 		usleep((philo->time_to_eat)); // время которое философ ел
// 		printf("eat up\n");
// 		usleep((philo->time_to_sleep) + (i * 1000)); // время сна
// 		philo->end = time_to(philo);
// 		time = (philo->end - philo->start);
// 		printf("time-->%d\n", time);
// 		if (time <= philo->time_to_die)
// 		{
// 			i++;
// 			// function ((void *)philo);
// 		}
// 		else
// 		{
// 			philo->i++;
// 			printf("philosopher -> die\n");
// 			printf("Exit_proc\n");
// 		}
// 	}
// 	return (NULL);
// }

// void	even_philosophers(t_philo *philo)
// {
// 	pthread_t	life_philo;

// 	printf("chetn\n");
// 	pthread_create(&life_philo, NULL, function, philo);
// 	pthread_detach(life_philo);
// }

// void	odd_philosophers(void)
// {
// 	printf("nechetn\n");
// }

void	creat_philo(t_philo *philo)
{
	if (philo->number_of_philosophers % 2 == 0)
	{
		printf("chetn\n");
		// while (philo->number_of_philosophers-- > 0)
		// {
		// 	philo->number++;
		// 	// printf("%d\n", philo.number);
		// 	if (philo->number == 1)
		// 		even_philosophers(&philo);
		// }
	}
	else
		printf("nechetn\n");
		// odd_philosophers();
}

int	values_philo(char *str[], t_philo *philo)
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
	philo.i = 0;
	if (argc >= 5 && argc <= 6)
	{
		philo.number = 0;
		i = values_philo(argv, &philo);
		printf("%d\n", philo.number_of_philosophers);
		printf("%d\n", philo.time_to_die);
		printf("%d\n", philo.time_to_eat);
		printf("%d\n", philo.time_to_sleep);
		printf("%d\n", philo.number_philosopher_must_eat);
		if (i == 1)
		{
			printf("Error");
			return (-1);
		}
		// creat_philo(&philo);
		// while (philo.i == 0)
		// 	pause();
		printf("Exit_philo\n");
		return (0);
	}
	else
		return (-1);
}
