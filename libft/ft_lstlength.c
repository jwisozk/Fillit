/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:39:39 by twill             #+#    #+#             */
/*   Updated: 2019/02/02 13:13:05 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlength(t_list **alst)
{
	t_list	*link;
	size_t	length;

	if (!alst || !*alst)
		return (0);
	link = *alst;
	length = 0;
	while (link)
	{
		link = link->next;
		length++;
	}
	return (length);
}
