/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:08:49 by kannie            #+#    #+#             */
/*   Updated: 2021/10/27 17:32:57 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	if (len == 0)
		return (b);
	else if (len > 0)
	{
		while (len > 0)
		{
			str[i] = c;
			len--;
			i++;
		}
		return (b);
	}
	else
		return (b);
}
