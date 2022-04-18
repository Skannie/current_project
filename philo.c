/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:48:26 by kannie            #+#    #+#             */
/*   Updated: 2022/04/18 17:12:25 by kannie           ###   ########.fr       */
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

void	*print(void *param)
{
	int	i;
	int	a;
	int	j;
	int	*b;

	b = (int *)param;
	i = 3;
	a = 0;
	while (a < i)
	{
		j = 0;
		while (b[j])
		{
			printf("%d ", b[j]);
			b[j]++;
			j++;
		}
		printf("\n");
		a++;
	}
	return (NULL);
}

void	function(void)
{
	pthread_t		s1;
	pthread_t		s2;
	int	b[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	pthread_create(&s1, NULL, print, (void *)b);
	pthread_join(s1, NULL);
	printf("Exit\n");
}

int	main(int argc, char *argv[])
{
	t_philo	philo;

	philo.i = 0;
	if (argc == 5)
	{
		philo.number_of_philosophers = ft_atoi(argv[1]);
		philo.time_to_die = ft_atoi(argv[2]);
		philo.time_to_eat = ft_atoi(argv[3]);
		philo.time_to_sleep = ft_atoi(argv[4]);
		function();
		return (0);
	}
	else
		return (1);
}
