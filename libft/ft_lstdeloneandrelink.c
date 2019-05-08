/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelandrelink.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:17:47 by twill             #+#    #+#             */
/*   Updated: 2019/03/28 14:24:44 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeloneandrelink(t_list **alst, t_list **lsttoremove,
		void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst || !lsttoremove || !*lsttoremove || !del)
		return ;
	if (*alst == *lsttoremove)
		*alst = (*lsttoremove)->next;
	else
	{
		tmp = *alst;
		while (tmp->next && tmp->next != *lsttoremove)
			tmp = tmp->next;
		if (tmp->next && tmp->next == *lsttoremove)
			tmp->next = (*lsttoremove)->next;
		else
			return ;
	}
	ft_lstdelone(lsttoremove, del);
}
