/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:52:09 by twill             #+#    #+#             */
/*   Updated: 2019/01/02 20:37:28 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	if (ft_isalpha(str[0]) && ft_islower(str[0]))
		str[0] = ft_toupper(str[0]);
	while (str[i + 1] != '\0')
	{
		if (!(ft_isalnum(str[i])) && ft_islower(str[i + 1]))
			str[i + 1] = ft_toupper(str[i + 1]);
		if (ft_isalnum(str[i]) && ft_isupper(str[i + 1]))
			str[i + 1] = ft_tolower(str[i + 1]);
		i++;
	}
	return (str);
}
