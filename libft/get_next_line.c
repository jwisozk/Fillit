/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:08:03 by twill             #+#    #+#             */
/*   Updated: 2019/04/15 19:32:21 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_gnl_free(t_list **clst, t_list **lst, char **line)
{
	if (clst && *clst)
		ft_lstdeloneandrelink(lst, clst, &ft_lstmemdel);
	ft_strdel(line);
	return (-1);
}

static int		ft_gnl_line_writer(char **line, t_list **clst, char **nl)
{
	if (!(*line = ft_strsub((*clst)->content, 0,
	*nl - (char *)((*clst)->content))))
		return (0);
	if (!((*nl = ft_strdup(*nl + 1))))
	{
		ft_strdel(nl);
		return (0);
	}
	ft_memdel(&((*clst)->content));
	(*clst)->content = *nl;
	return (1);
}

static ssize_t	ft_gnl_read(const int fd, char **line, t_list **clst)
{
	ssize_t	input;
	char	buf[BUFF_SIZE + 1];
	char	*nl;

	while ((input = read(fd, buf, BUFF_SIZE)))
	{
		if (input == -1)
			return (-1);
		buf[input] = '\0';
		nl = (*clst)->content;
		if (!((*clst)->content = ft_strjoin((*clst)->content, buf)))
		{
			ft_strdel(&nl);
			return (-1);
		}
		ft_strdel(&nl);
		if ((nl = (ft_strchr((*clst)->content, '\n'))))
		{
			if (!ft_gnl_line_writer(line, clst, &nl))
				return (-1);
			break ;
		}
	}
	return (input);
}

static ssize_t	ft_gnl_return(const int fd, char **line, t_list **lst,
				t_list **clst)
{
	ssize_t	input;
	char	*nl;

	input = ft_gnl_read(fd, line, clst);
	if (!*line && (*clst)->content)
	{
		if ((nl = ft_strchr((*clst)->content, '\n')))
		{
			if (!ft_gnl_line_writer(line, clst, &nl))
				return (-1);
		}
		else
		{
			*line = NULL;
			ft_memdel(&((*clst)->content));
		}
	}
	if ((*clst)->content && *((char *)((*clst)->content)) == '\0')
		ft_memdel(&((*clst)->content));
	if ((*clst)->content && !ft_lstsearchcontentsize(lst, fd))
		ft_lstadd(lst, *clst);
	return (input);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*clst;
	ssize_t			input;

	if ((clst = NULL) || BUFF_SIZE <= 0 || !line ||
	BUFF_SIZE != BUFF_SIZE * 10 / 10 || (*line = NULL) ||
	fd != fd * 10 / 10 || fd < 0 || read(fd, NULL, 0) < 0)
		return (ft_gnl_free(&clst, &lst, line));
	clst = lst ? ft_lstsearchcontentsize(&lst, fd) : clst;
	if (!clst)
		if (!(clst = ft_lstnew(NULL, 0)) ||
		!((clst->content_size = fd) ? 1 : 1))
			return (ft_gnl_free(&clst, &lst, line));
	if ((input = ft_gnl_return(fd, line, &lst, &clst)) == -1)
		return (ft_gnl_free(&clst, &lst, line));
	if (clst && !(clst->content))
	{
		if (ft_lstsearchcontentsize(&lst, fd))
			ft_lstdeloneandrelink(&lst, &clst, &ft_lstmemdel);
		else
			ft_lstdelone(&clst, &ft_lstmemdel);
	}
	if (!input)
		return (*line ? 1 : 0);
	return (1);
}
