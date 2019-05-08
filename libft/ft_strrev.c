/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:33:17 by twill             #+#    #+#             */
/*   Updated: 2019/01/16 19:56:18 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char		*newstr;
	size_t		len;
	ssize_t		i;
	size_t		j;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len != len * 10 / 10)
		return (NULL);
	if (!(newstr = (char *)ft_memalloc(len + 1)))
		return (NULL);
	i = len - 1;
	j = 0;
	while (i > -1)
		newstr[j++] = str[i--];
	newstr[j] = '\0';
	return (newstr);
}
