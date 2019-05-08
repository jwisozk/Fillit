/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:08:31 by twill             #+#    #+#             */
/*   Updated: 2018/12/13 22:23:22 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*newsrc;
	unsigned char	*newdst;

	newsrc = (unsigned char *)src;
	newdst = (unsigned char *)dst;
	i = 0;
	while (i != n)
	{
		newdst[i] = newsrc[i];
		if (newsrc[i] == (unsigned char)c)
			return ((unsigned char *)(newdst + i + 1));
		i++;
	}
	newdst = NULL;
	return (newdst);
}
