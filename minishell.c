/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:16:52 by kannie            #+#    #+#             */
/*   Updated: 2022/06/20 17:29:38 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_token	token;
	char	*str;
	char	*line;

	while (1)
	{
		str = readline("minishell $ ");
		token.next = NULL;
		token.pre = NULL;
		if (str == NULL)
			break ;
		line = runstr(str);
		printf("str->%s\nline->%s\n", str, line);
		free(str);
	}
	return (0);
}

	// int	i;
	// int	s;
	// i = fork();
	// s = fork();
	// printf("%d %d\n", i, s);
	// if (i == 0)
		// execve("/bin/ls", argv, env);
	// write(1, "fewgewrgwergw", 20);

	// printf("--->\n");