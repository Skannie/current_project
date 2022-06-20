/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:28:10 by kannie            #+#    #+#             */
/*   Updated: 2022/06/20 17:29:44 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skipp_spase(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
	{
		if (str[i + 1] != ' ')
			break ;
		i++;
	}
	return (i);
}

char	*init_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = (int)ft_strlen(str);
	line = (char *) malloc (sizeof (char) * (j + 1));
	if (!line)
		return (NULL);
	line[j] = '\0';
	while (line[i] != '\0')
	{
		line[i] = ' ';
		i++;
	}
	return (line);
}

char	*runstr(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	str = ft_strtrim(str, " ");
	line = init_line(str);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
			i = skipp_spase(str, i);
		line[j] = str[i];
		i++;
		j++;
	}
	line = ft_strtrim(line, " ");
	return (line);
}
