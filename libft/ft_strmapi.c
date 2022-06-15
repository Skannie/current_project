/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:52:33 by kannie            #+#    #+#             */
/*   Updated: 2021/11/14 14:07:22 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*zna;
	int		i;

	i = 0;
	if (!f || !s)
		return (NULL);
	zna = malloc(ft_strlen(s) + 1);
	if (! zna)
		return (NULL);
	while (s[i] != '\0')
	{
		zna[i] = f(i, s[i]);
		i++;
	}
	zna[i] = '\0';
	return (zna);
}
