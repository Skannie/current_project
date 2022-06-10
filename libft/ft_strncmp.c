/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:06 by kannie            #+#    #+#             */
/*   Updated: 2021/10/22 18:38:56 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i] && i != n)
	{
		if ((s1[i] || s2[i]) == '\0')
			return (0);
		i++;
	}
	if (n == i)
		return (0);
	return (str1[i] - str2[i]);
}
