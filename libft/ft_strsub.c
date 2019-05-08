/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:00:35 by twill             #+#    #+#             */
/*   Updated: 2019/03/28 15:28:55 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strsub_free(char **newstr)
{
	if (newstr && *newstr)
	{
		free(*newstr);
		*newstr = NULL;
	}
	return (NULL);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	stlen;
	size_t	i;

	if (!s || !(s + start) || len != len * 10 / 10)
		return (NULL);
	if (!(stlen = ft_strlen(s + start)) || stlen != stlen * 10 / 10)
		return (NULL);
	if (len >= stlen)
	{
		if (!(newstr = ft_strdup(s + start)))
			return (ft_strsub_free(&newstr));
	}
	else
	{
		if (!(newstr = (char *)ft_memalloc(len + 1)))
			return (ft_strsub_free(&newstr));
		i = -1;
		while (++i < len && s[i] != '\0')
			newstr[i] = s[i + start];
		newstr[i] = '\0';
	}
	return (newstr);
}
