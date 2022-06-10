/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:16:52 by kannie            #+#    #+#             */
/*   Updated: 2022/06/10 18:19:53 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_token	token;
	char	*str;

	while (1)
	{
		str = ft_readline(str);
		token.next = NULL;
		token.pre = NULL;
		printf("%s\n", token.str);
		free(token.str);
		if (token.str == NULL)
			break ;
	}
	return (0);
}

char	*ft_readline(char *str)
{
	int	i;

	i = 0;
	str = readline("minishell $ ");
	ft_strlen(str);
}

	// int	i;
	// int	s;
	// i = fork();
	// s = fork();
	// printf("%d %d\n", i, s);
	// if (i == 0)
		// execve("/bin/ls", argv, env);
	// write(1, "fewgewrgwergw", 20);