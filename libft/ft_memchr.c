/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:33:01 by twill             #+#    #+#             */
/*   Updated: 2018/12/12 17:28:13 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*start;
	const unsigned char		*finish;

	start = s;
	finish = s + n;
	while (start < finish)
	{
		if (*start == (unsigned char)c)
			return (void *)(start);
		start++;
	}
	return (NULL);
}
