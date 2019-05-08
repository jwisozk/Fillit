/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_arr_shapes_and_get_size.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:11:23 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/15 21:19:09 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_find_size_of_square(int num)
{
	static int	a[] = {5, 10, 17, 26};
	int			size;
	int			i;

	i = 0;
	size = 4;
	while (num >= a[i] && i < 4)
	{
		i++;
		size += 2;
	}
	return (size);
}

static int		ft_sqrt(int num)
{
	int	n;

	n = 2;
	while (n * n < num)
		n++;
	return (n);
}

static int		ft_get_size_of_map(int n, int h, int w)
{
	int	size;
	int	sqrt;

	sqrt = ft_sqrt(n * 4);
	if (n == 1)
		size = h > w ? h : w;
	else if (n > 1 && h == w && w == 2)
		size = ft_find_size_of_square(n);
	else
	{
		size = h > w ? h : w;
		size = size > sqrt ? size : sqrt;
	}
	return (size);
}

static t_size	ft_get_letter_combs_h_w(int arr_index[26], t_shape *arr_shapes)
{
	static char arr_valid_maps[19][12][5] = VALID_MAPS;
	t_size		sh;
	int			i;

	sh.h = 0;
	sh.w = 0;
	i = 0;
	while (i < MAX_COUNT && arr_index[i] != 0)
	{
		arr_shapes[i].letter = 65 + i;
		arr_shapes[i].comb = arr_valid_maps[arr_index[i] - 1][0];
		arr_shapes[i].h = arr_valid_maps[arr_index[i] - 1][1][0] - '0';
		arr_shapes[i].w = arr_valid_maps[arr_index[i] - 1][1][1] - '0';
		sh.h = arr_shapes[i].h > sh.h ? arr_shapes[i].h : sh.h;
		sh.w = arr_shapes[i].w > sh.w ? arr_shapes[i].w : sh.w;
		i++;
	}
	arr_shapes[i].letter = '\0';
	return (sh);
}

int				ft_fill_arrsh_get_size(t_shape *arr_sh, int arr_i[26], int n)
{
	int		size;
	t_size	sh;

	sh = ft_get_letter_combs_h_w(arr_i, arr_sh);
	size = ft_get_size_of_map(n, sh.h, sh.w);
	return (size);
}
