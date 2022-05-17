/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:18 by kannie            #+#    #+#             */
/*   Updated: 2022/05/17 21:25:31 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_exit(int i)
{
	if (i == -1)
		printf("Error\n");
	else
		printf("Exit_philo\n");
	return (i);
}

int	main(int argc, char **argv)
{
	t_waiter	waiter;
	int			i;

	i = 0;
	waiter.info = 0;
	if (argc >= 5 && argc <= 6)
	{
		waiter.info = values_waiter(argv, &waiter);
		if (waiter.info < 0)
			return (print_exit(waiter.info));
		waiter.info = create_philo(&waiter);
		if (waiter.info < 0)
			return (print_exit(waiter.info));
		if (waiter.sig_eat == 1)
			free (waiter.num_eat);
		return (print_exit(waiter.info));
	}
	else
		return (print_exit(1));
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