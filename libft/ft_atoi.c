/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:19:43 by kannie            #+#    #+#             */
/*   Updated: 2021/10/26 20:33:57 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (str[a] >= 48 && str[a] <= 57)
	{
		b = schar_v_int(str, a, minus);
		return (b);
	}
	else
		return (0);
}
