/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:47:47 by twill             #+#    #+#             */
/*   Updated: 2019/04/15 20:22:58 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"
# define MAX_COUNT 26
# define IND_FIG 4
# define SUBOBJ_1 "0330", "00CC", "0066", "0033", ""
# define OB1 {"0156", "22", "CC00", "6600", "3300", "0CC0", "0660", SUBOBJ_1}
# define OB2 {"056B", "32", "8C40", "4620", "2310", "08C4", "0462", "0231", ""}
# define OB3 {"1256", "23", "6C00", "3600", "06C0", "0360", "006C", "0036", ""}
# define OB4 {"156A", "32", "4C80", "2640", "1320", "04C8", "0264", "0132", ""}
# define OB5 {"0167", "23", "C600", "6300", "0C60", "0630", "00C6", "0063", ""}
# define OB6 {"0127", "23", "E200", "7100", "0E20", "0710", "00E2", "0071", ""}
# define OB7 {"0567", "23", "8E00", "4700", "08E0", "0470", "008E", "0047", ""}
# define OB8 {"015A", "32", "C880", "6440", "3220", "0C88", "0644", "0322", ""}
# define OB9 {"16AB", "32", "44C0", "2260", "1130", "044C", "0226", "0113", ""}
# define OB10 {"0123", "14", "F000", "0F00", "00F0", "000F", ""}
# define OB11 {"05AF", "41", "8888", "4444", "2222", "1111", ""}
# define OB12 {"016B", "32", "C440", "6220", "3110", "0C44", "0622", "0311", ""}
# define OB13 {"0125", "23", "E800", "7400", "0E80", "0740", "00E8", "0074", ""}
# define OB14 {"05AB", "32", "88C0", "4460", "2230", "088C", "0446", "0223", ""}
# define OB15 {"2567", "23", "2E00", "1700", "02E0", "0170", "002E", "0017", ""}
# define OB16 {"1567", "23", "4E00", "2700", "04E0", "0270", "004E", "0027", ""}
# define OB17 {"056A", "32", "8C80", "4640", "2320", "08C8", "0464", "0232", ""}
# define OB18 {"0126", "23", "E400", "7200", "0E40", "0720", "00E4", "0072", ""}
# define OB19 {"156B", "32", "4C40", "2620", "1310", "04C4", "0262", "0131", ""}
# define SUBOBJ_2 OB1, OB2, OB3, OB4, OB5, OB6, OB7
# define SUBOBJ_3 OB8, OB9, OB10, OB11, OB12, OB13, OB14
# define SUBOBJ_4 OB15, OB16, OB17, OB18, OB19
# define VALID_MAPS {SUBOBJ_2, SUBOBJ_3, SUBOBJ_4}

typedef struct	s_shape {
	char	letter;
	char	*comb;
	int		h;
	int		w;
	int		cords[4];
	int		temp[4];
}				t_shape;
typedef struct	s_size
{
	int h;
	int w;
}				t_size;
int				ft_fillit(t_shape *arr_shapes, int size, int num);
int				ft_read_and_validate(int fd, int arr_index[MAX_COUNT]);
int				ft_fill_arrsh_get_size(t_shape *arr_sh, int arr_i[26], int n);
int				ft_recursion(int j, t_shape *arr_shapes, char *map, int size);
void			ft_arr_cleaner(int *arr, int num);
#endif
