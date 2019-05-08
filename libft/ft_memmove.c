/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:16:25 by twill             #+#    #+#             */
/*   Updated: 2019/01/03 00:11:27 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*newdst;
	const char	*newsrc;

	if (!dst && !src)
		return (NULL);
	newdst = dst;
	newsrc = src;
	if (dst < src)
	{
		while (len--)
			*newdst++ = *newsrc++;
	}
	else if (dst > src)
	{
		newdst = newdst + len - 1;
		newsrc = newsrc + len - 1;
		while (len--)
			*newdst-- = *newsrc--;
	}
	return (dst);
}
