/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:08:14 by twill             #+#    #+#             */
/*   Updated: 2019/04/15 21:21:12 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	ft_read_line(char *line)
{
	int		nbr;
	char	character;

	nbr = 0;
	if (line[0] == '#')
		nbr = 8;
	if (line[1] == '#')
		nbr = nbr + 4;
	if (line[2] == '#')
		nbr = nbr + 2;
	if (line[3] == '#')
		nbr = nbr + 1;
	character = (nbr <= 9) ? (nbr + '0') : (nbr + 'A' - 10);
	return (character);
}

static	int		ft_check_valid_characters(char *line)
{
	while (*line != '\0')
	{
		if (*line != '#' && *line != '.')
			return (0);
		line++;
	}
	return (1);
}

static	int		ft_close_and_compare(int *i, int *j, char arr_combs[27][5])
{
	int			k;
	int			l;
	static char arr_valid_maps[19][12][5] = VALID_MAPS;

	k = 0;
	if (*j == 0)
		return (0);
	arr_combs[*i][*j] = '\0';
	(*i)++;
	*j = 0;
	while (k < 19)
	{
		l = 2;
		while (l < 12)
		{
			if (ft_strequ("", arr_valid_maps[k][l]))
				break ;
			if (ft_strequ(arr_combs[*i - 1], arr_valid_maps[k][l]))
				return (k + 1);
			l++;
		}
		k++;
	}
	return (0);
}

static int		ft_read_and_validate_base(int fd, int *arr_index, char **line)
{
	char	arr_combs[MAX_COUNT][IND_FIG + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < MAX_COUNT && get_next_line(fd, &(*line)) > 0)
	{
		if (**line == '\0')
		{
			ft_strdel(&(*line));
			if (!(arr_index[i - 1] = ft_close_and_compare(&i, &j, arr_combs)))
				return (0);
			continue ;
		}
		if ((ft_strlen(*line) != 4) || !(ft_check_valid_characters(*line)))
			return (0);
		arr_combs[i][j] = ft_read_line(*line);
		ft_strdel(&(*line));
		j++;
	}
	if (!(arr_index[i - 1] = ft_close_and_compare(&i, &j, arr_combs)) ||
			(i > 26 || i <= 0))
		return (0);
	return (i);
}

int				ft_read_and_validate(int fd, int *arr_index)
{
	char	*line;
	int		status;

	status = ft_read_and_validate_base(fd, arr_index, &line);
	ft_strdel(&line);
	return (status);
}
