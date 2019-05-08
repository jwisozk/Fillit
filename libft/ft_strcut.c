/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:02:16 by twill             #+#    #+#             */
/*   Updated: 2019/01/16 21:24:45 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s1, size_t newlen)
{
	char	*newstr;
	size_t	i;
	size_t	initlen;

	if (!s1)
		return (NULL);
	initlen = ft_strlen(s1);
	if (newlen > initlen)
	{
		if (initlen != initlen * 10 / 10)
			return (NULL);
		newstr = ft_strdup(s1);
	}
	else
	{
		if (newlen != newlen * 10 / 10)
			return (NULL);
		if (!(newstr = (char *)ft_memalloc(newlen + 1)))
			return (NULL);
		i = -1;
		while (++i < newlen && s1[i] != '\0')
			newstr[i] = s1[i];
		newstr[i] = '\0';
	}
	return (newstr);
}
