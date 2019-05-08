/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:12:01 by twill             #+#    #+#             */
/*   Updated: 2019/02/05 19:32:59 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			s = ft_strchr(s + 1, c);
		}
	}
	return (count);
}

static void		*ft_freearray(char **root)
{
	size_t	i;

	if (!root)
		return (NULL);
	i = 0;
	while (*(root + i))
	{
		free(*(root + i));
		i++;
	}
	free(root);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**root;
	size_t	j;

	if (!s || !(count = ft_wordcount(s, c)) || count != count * 10 / 10)
		return (NULL);
	if (!(root = (char **)ft_memalloc(sizeof(root) * (count + 1))))
		return (NULL);
	*(root + count) = NULL;
	j = 0;
	while (s && *s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			if (!(*(root + j++) = ft_strsub(s, 0,
			(ft_strchr(s, c) ? ft_strchr(s, c) - s : ft_strlen(s)))))
				return (ft_freearray(root));
			if (!(ft_strchr(s, c)))
				break ;
			s = ft_strchr(s, c) ? ft_strchr(s + 1, c) : s;
		}
	}
	return (root);
}
