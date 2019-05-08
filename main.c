/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:57:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/15 21:58:31 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_print_error(void)
{
	ft_putstr("error");
	ft_putchar('\n');
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		arr_index[MAX_COUNT];
	t_shape	*arr_shapes;
	int		num;
	int		size;

	ft_arr_cleaner(arr_index, MAX_COUNT);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (ft_print_error());
		if (!(num = ft_read_and_validate(fd, arr_index)))
			return (ft_print_error());
		if (!(arr_shapes = (t_shape *)malloc(sizeof(*arr_shapes) * (num + 1))))
			return (ft_print_error());
		size = ft_fill_arrsh_get_size(arr_shapes, arr_index, num);
		if (!(ft_fillit(arr_shapes, size, num)))
			return (ft_print_error());
		if (close(fd) == -1)
			return (ft_print_error());
	}
	else
		ft_putstr("usage: ./fillit [filename]\n");
	return (0);
}
