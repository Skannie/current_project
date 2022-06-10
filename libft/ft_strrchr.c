/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:44:49 by kannie            #+#    #+#             */
/*   Updated: 2021/11/14 19:37:04 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c >= 0 && (unsigned char)c <= 127)
	{
		while (str[i] != '\0')
			i++;
		while (str[i] != (unsigned char)c && i != 0)
			i--;
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		else
			return (0);
	}
	else
		return (0);
}
