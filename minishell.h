/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:40:08 by kannie            #+#    #+#             */
/*   Updated: 2022/06/20 17:24:00 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include "./libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define EMPTY	0
# define ARG	1

typedef struct s_token
{
	int				key;
	char			*str;
	struct s_token	*next;
	struct s_token	*pre;
}	t_token;

int		skipp_spase(char *str, int i);
char	*runstr(char *str);
char	*init_line(char *str);

#endif