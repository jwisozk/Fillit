/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changenchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:24:08 by twill             #+#    #+#             */
/*   Updated: 2019/02/19 23:55:40 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_changenchr(char *str, char old, char new)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == old)
		{
			str[i] = new;
			j++;
		}
		i++;
	}
	return (j);
}
