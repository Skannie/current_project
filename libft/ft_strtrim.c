/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:41:53 by kannie            #+#    #+#             */
/*   Updated: 2021/11/15 16:35:30 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	a;

	a = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	str = ft_substr((char *)s1, 0, i + 1);
	return (str);
}
