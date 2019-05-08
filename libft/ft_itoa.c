/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:15:38 by twill             #+#    #+#             */
/*   Updated: 2019/01/16 20:30:33 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(ssize_t nn)
{
	size_t	i;

	i = nn < 0 ? 1 : 0;
	nn = nn < 0 ? -nn : nn;
	i = nn == 0 ? i + 1 : i;
	while (nn > 0)
	{
		nn = nn / 10;
		i++;
	}
	return (++i);
}

char			*ft_itoa(int n)
{
	int		neg;
	ssize_t	nn;
	size_t	size;
	char	*str;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	neg = n < 0 ? 1 : 0;
	nn = n;
	size = ft_size(nn);
	nn = n < 0 ? -nn : nn;
	if (!(str = (char *)ft_memalloc(size)))
		return (NULL);
	i = 0;
	while (nn != 0)
	{
		str[i++] = '0' + nn % 10;
		nn = (nn - nn % 10) / 10;
	}
	str[i] = '0' + nn % 10;
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
