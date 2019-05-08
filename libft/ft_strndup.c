/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:49:03 by twill             #+#    #+#             */
/*   Updated: 2019/02/05 23:54:11 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*newstr;
	size_t	i;

	if (n != n * 10 / 10)
		return (NULL);
	if (!(newstr = (char *)ft_memalloc(n + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
