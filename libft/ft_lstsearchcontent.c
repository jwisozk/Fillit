/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:28:45 by twill             #+#    #+#             */
/*   Updated: 2019/02/13 22:47:08 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearchcontent(t_list **alst, void *content)
{
	t_list	*lst;

	if (!alst || !*alst || !content)
		return (NULL);
	lst = *alst;
	while (lst->next)
	{
		if (ft_strequ((char *)(lst->content), (char *)content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
