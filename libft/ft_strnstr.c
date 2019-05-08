/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:09:42 by twill             #+#    #+#             */
/*   Updated: 2018/12/18 19:39:16 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*where;
	char	*what;
	size_t	wherelen;
	size_t	whatlen;
	size_t	i;

	where = (char *)haystack;
	what = (char *)needle;
	wherelen = ft_strlen(where);
	whatlen = ft_strlen(what);
	i = 0;
	if (whatlen > wherelen)
		return (NULL);
	if (whatlen == 0)
		return (where);
	while (i <= wherelen - whatlen && whatlen + i < len + 1)
	{
		if (!(ft_strncmp(where + i, what, whatlen)))
			return (where + i);
		i++;
	}
	return (NULL);
}
