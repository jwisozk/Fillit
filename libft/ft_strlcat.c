/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:53:38 by twill             #+#    #+#             */
/*   Updated: 2019/01/10 20:48:17 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t	dlen;
	size_t	slen;
	size_t	total;

	d = dst;
	dlen = ft_strlen(d);
	slen = ft_strlen(src);
	total = size > dlen ? dlen + slen : slen + size;
	if (size > dlen + 1)
	{
		ft_strncat(d, src, size - dlen - 1);
		*(d + ft_strlen(d)) = '\0';
	}
	return (total);
}
