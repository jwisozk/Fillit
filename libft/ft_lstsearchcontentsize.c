/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:28:45 by twill             #+#    #+#             */
/*   Updated: 2019/02/13 22:46:49 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearchcontentsize(t_list **alst, size_t content_size)
{
	t_list	*lst;

	if (!alst)
		return (NULL);
	lst = *alst;
	while (lst)
	{
		if (lst->content_size == content_size)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
