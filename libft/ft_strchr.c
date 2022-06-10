/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:31:04 by kannie            #+#    #+#             */
/*   Updated: 2021/11/15 15:24:28 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c >= 0)
	{
		while (str[i] != '\0' && (unsigned char)c != str[i])
		{
			i++;
		}
		if ((unsigned char)c != str[i])
			return (NULL);
		return (&str[i]);
	}
	else
		return (NULL);
}
