/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:08:31 by twill             #+#    #+#             */
/*   Updated: 2019/01/16 21:14:02 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*newsrc;
	char	*newdst;

	if (!dst && !src)
		return (NULL);
	newsrc = (char *)src;
	newdst = (char *)dst;
	i = 0;
	while (i != n)
	{
		newdst[i] = newsrc[i];
		i++;
	}
	return (dst);
}
