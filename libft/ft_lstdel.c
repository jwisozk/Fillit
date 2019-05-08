/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:39:39 by twill             #+#    #+#             */
/*   Updated: 2019/02/02 12:13:08 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*tmp;

	if (!alst || !*alst || !del)
		return ;
	link = *alst;
	while (link)
	{
		tmp = link->next;
		ft_lstdelone(&link, del);
		link = tmp;
	}
	*alst = NULL;
}
