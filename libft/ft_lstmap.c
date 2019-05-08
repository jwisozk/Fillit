/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:34:38 by twill             #+#    #+#             */
/*   Updated: 2019/01/30 18:05:15 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstfree(t_list *lst)
{
	t_list	*start;
	t_list	*next;

	start = lst;
	while (lst)
	{
		free(lst->content);
		lst = lst->next;
	}
	lst = start;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*prev;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	if (!(lst2 = f(lst)))
		return (NULL);
	ptr = lst2;
	prev = lst2;
	lst = lst->next;
	while (lst)
	{
		if (!(lst2 = f(lst)))
			return (ft_lstfree(ptr));
		prev->next = lst2;
		prev = lst2;
		lst = lst->next;
	}
	return (ptr);
}
