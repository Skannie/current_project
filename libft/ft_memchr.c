/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:50:59 by kannie            #+#    #+#             */
/*   Updated: 2021/11/15 14:53:08 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str1;

	i = 0;
	str1 = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str1[i] == (unsigned char)c)
			return (str1 + i);
		i++;
	}
	return (NULL);
}
