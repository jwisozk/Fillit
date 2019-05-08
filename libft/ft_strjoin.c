/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:17:25 by twill             #+#    #+#             */
/*   Updated: 2019/02/26 19:47:06 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if ((s1 && !s2) || (!s1 && s2))
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((len1 + len2) != (len1 + len2) * 10 / 10)
		return (NULL);
	if (!(newstr = (char *)ft_memalloc(len1 + len2 + 1)))
		return (NULL);
	i = -1;
	while (++i <= len1 + len2)
		newstr[i] = i < len1 ? s1[i] : s2[i - len1];
	return (newstr);
}
