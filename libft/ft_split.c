/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:26:31 by kannie            #+#    #+#             */
/*   Updated: 2021/11/15 15:19:29 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	colv_mas(char const *s, char c)
{
	int	i;
	int	a;
	int	l;

	a = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		l = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (l != i)
			a++;
	}
	return (a);
}

void	free_mass(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**zap_v_str(char **str, int i, char const *s, char c)
{
	int	a;
	int	z;
	int	l;

	l = 0;
	a = 0;
	while (i > l)
	{
		while (s[a] == c)
			a++;
		z = a;
		while (s[z] != c && s[z] != '\0')
			z++;
		str[l] = (char *)malloc(sizeof(char) * (z - a + 1));
		if (str[l] == NULL)
		{
			free_mass(str);
			return (NULL);
		}
		ft_strlcpy(str[l], &s[a], (z - a + 1));
		a = z;
		l++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;

	if (s == NULL)
		return (NULL);
	i = colv_mas(s, c);
	str = (char **)malloc(sizeof(char *) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = NULL;
	str = zap_v_str(str, i, s, c);
	return (str);
}
