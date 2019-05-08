/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:39:29 by twill             #+#    #+#             */
/*   Updated: 2019/04/14 19:04:48 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	long	n;
	long	tmp;

	while (ft_isspace(*str))
		str++;
	if (*str == '-' && *(str + 1) == '+')
		return (0);
	neg = *str == '-' ? 1 : 0;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		tmp = n * 10;
		if (n != tmp / 10 || (n = tmp + (*(str++) - '0')) < 0)
			return (neg ? 0 : -1);
	}
	return (neg ? (int)-n : (int)n);
}
