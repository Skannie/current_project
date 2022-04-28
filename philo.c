/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:18 by kannie            #+#    #+#             */
/*   Updated: 2022/04/28 16:35:08 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(int i)
{
	printf("Error");
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
		printf("Exit_philo\n");
		return (0);
	}
	else
		return (1);
}

// pthread_mutex_t	mutex; - создание переменной мьютекс
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