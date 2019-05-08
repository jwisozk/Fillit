/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:21:46 by twill             #+#    #+#             */
/*   Updated: 2019/03/28 14:23:28 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if (size * 10 / 10 != size)
		return (NULL);
	if (!(ptr = (char *)malloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memset(ptr, 0, size);
	return ((void *)ptr);
}
