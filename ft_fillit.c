/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:23:16 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/15 22:29:26 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		max_coords_recount(int map_size, char *tetrimino, int cords[4])
{
	int	i;

	i = 0;
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i] == 'F')
			cords[i] = (map_size - 4) * 3 + 15;
		else if (tetrimino[i] >= 'A' && tetrimino[i] <= 'E')
			cords[i] = (map_size - 4) * 2 + tetrimino[i] - 'A' + 10;
		else if (tetrimino[i] >= '5' && tetrimino[i] <= '9')
			cords[i] = map_size - 4 + tetrimino[i] - '0';
		else
			cords[i] = tetrimino[i] - '0';
		i++;
	}
}

static void		ft_add_cords_in_arr_shapes(t_shape *arr_sh, int size, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		max_coords_recount(size, arr_sh[i].comb, arr_sh[i].cords);
		i++;
	}
}

static char		*ft_create_empty_map(int size)
{
	char	*map;
	int		i;

	if (!(map = malloc((size + 1) * size)))
		return (NULL);
	ft_memset((void *)map, '.', size * (size + 1));
	i = 1;
	while (i < size)
	{
		map[(size + 1) * i - 1] = '\n';
		i++;
	}
	map[(size + 1) * size - 1] = '\0';
	return (map);
}

int				ft_fillit(t_shape *arr_shapes, int size, int num)
{
	char	*map;

	if (!(map = ft_create_empty_map(size)))
		return (0);
	ft_add_cords_in_arr_shapes(arr_shapes, size, num);
	while (ft_recursion(0, arr_shapes, map, size) == 0)
	{
		size++;
		ft_add_cords_in_arr_shapes(arr_shapes, size, num);
		ft_strdel(&map);
		map = ft_create_empty_map(size);
	}
	ft_putstr(map);
	ft_putchar('\n');
	ft_strdel(&map);
	ft_memdel((void **)&arr_shapes);
	return (1);
}
