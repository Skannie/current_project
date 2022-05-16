/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:18 by kannie            #+#    #+#             */
/*   Updated: 2022/05/16 19:56:11 by kannie           ###   ########.fr       */
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

	waiter.info = 0;
	if (argc >= 5 && argc <= 6)
	{
		waiter.info = values_waiter(argv, &waiter);
		if (waiter.info < 0)
			return (error_exit(waiter.info));
		waiter.info = create_philo(&waiter);
		if (waiter.info < 0)
			return (error_exit(waiter.info));
		while (waiter.p_kill == 0 && waiter.sig_eat == 0)
		{
			if (waiter.must_eat > 0)
				if (f_waiter(&waiter) > 0)
					waiter.sig_eat = 1;
			continue ;
		}
		usleep(100);
		printf("Exit_philo\n");
		return (0);
	}
	else
		return (error_exit(1));
}

// pthread_mutex_t	mutex; - создание переменной мьютекс
// pthread_mutex_init(&mutex, NULL); - инициализация мьютекс
// pthread_mutex_destroy(&mutex); - уничтожение мьютекс
// pthread_mutex_lock(&mutex); - блокировка мьютексом
// pthread_mutex_unlock(&mutex); - разблокировка мьютексом
// pthread_create(&s1, NULL, print, (void *)b); - создаёт параллельный поток
// pthread_detach(s1); - не ждёт завершения потока s1 и идёт дальше
// pthread_join(s1, NULL); - ждёт завершения потока s1 после чего идёт дальше
// usleep(100000); - команда говорит ждать в течении N времени (в микросекудах)
// void	*print(void *param);