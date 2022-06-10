/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:08:19 by kannie            #+#    #+#             */
/*   Updated: 2021/11/08 17:09:12 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (i != len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		while (len != 0)
		{
			*(unsigned char *)((dst - 1) + len)
				= *(unsigned char *)((src - 1) + len);
			len--;
		}
	}
	return (dst);
}
