/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:10:02 by kannie            #+#    #+#             */
/*   Updated: 2021/11/15 16:55:17 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vstepen_it(int a)
{
	int			i;
	long int	step;

	i = 0;
	step = 1;
	while (a > i)
	{
		step = 10 * step;
		i++;
	}
	return (step);
}

char	*podschet_it(long long zadan, int sum, char *fd)
{
	int				i;
	long long		l;

	i = 0;
	if (fd[0] == '-')
		i = 1;
	if (zadan == 0)
	{
		fd[0] = 0 + 48;
		i++;
	}
	else
	{
		while (sum > 0)
		{
			l = (zadan / vstepen_it(sum - 1));
			fd[i] = (l % 10 + 48);
			sum--;
			i++;
		}
	}
	fd[i] = '\0';
	return (fd);
}

char	*ft_itoa(int n)
{
	long long		i;
	int				b;
	char			*str;

	i = n;
	b = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (i != 0)
	{
		i = i / 10;
		b++;
	}
	str = (char *)malloc(sizeof(char) * (b + 2));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = (long long)n * (-1);
		str = podschet_it(i, b, str);
	}
	else
		str = podschet_it(n, b, str);
	return (str);
}
