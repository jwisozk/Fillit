/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:01:23 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/15 18:36:44 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_put_tetrimino(t_shape *arr_shapes, char *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[arr_shapes->temp[i]] = arr_shapes->letter;
		i++;
	}
}

static int	ft_put_tetr_on_map(t_shape *arr_shapes, char *map, int size, int j)
{
	int	x;
	int	y;
	int	len;

	ft_arr_cleaner(arr_shapes->temp, 4);
	len = (size + 1) * size - 1;
	x = 0;
	y = 0;
	while (y < 4 && arr_shapes->cords[y] + j + x < len)
	{
		y = 0;
		while (y < 4 && arr_shapes->cords[y] + j + x < len)
		{
			if (map[arr_shapes->cords[y] + j + x] != '.')
				break ;
			arr_shapes->temp[y] = arr_shapes->cords[y] + j + x;
			y++;
		}
		x++;
	}
	if (arr_shapes->temp[3] == 0)
		return (0);
	ft_put_tetrimino(arr_shapes, map);
	return (1);
}

static void	ft_remove_letter(t_shape *arr_shapes, char *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[arr_shapes->temp[i]] = '.';
		i++;
	}
}

int			ft_recursion(int j, t_shape *arr_shapes, char *map, int size)
{
	if (arr_shapes->letter == '\0')
		return (1);
	while (ft_put_tetr_on_map(arr_shapes, map, size, j))
	{
		if ((ft_recursion(0, arr_shapes + 1, map, size)))
			return (1);
		j = arr_shapes->temp[0] + 1;
		if (arr_shapes->cords[0] == 1)
			j--;
		else if (arr_shapes->cords[0] == 2)
			j = j - 2;
		ft_remove_letter(arr_shapes, map);
	}
	return (0);
}
