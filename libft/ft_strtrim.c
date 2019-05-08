/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:43:49 by twill             #+#    #+#             */
/*   Updated: 2019/01/12 20:39:43 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*n;
	size_t	len;
	size_t	l;

	if (!s)
		return (NULL);
	if (!(n = ft_strdup(s)))
		return (NULL);
	while (ft_isblank(*n) || *n == '\n')
		n++;
	if ((len = ft_strlen(n)))
	{
		l = len - 1;
		while ((ft_isblank(n[l]) || n[l] == '\n') && l != 0)
			n[l--] = '\0';
	}
	if (!(n = ft_strdup(n)))
		return (NULL);
	return (n);
}
