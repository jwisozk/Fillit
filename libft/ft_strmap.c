/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:14:35 by twill             #+#    #+#             */
/*   Updated: 2019/01/16 22:43:45 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*newstr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len != len * 10 / 10)
		return (NULL);
	if (!(newstr = (char *)ft_memalloc(len + 1)))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		newstr[i] = f(s[i]);
	newstr[i] = '\0';
	return (newstr);
}
