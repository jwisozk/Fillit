# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twill <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 20:19:57 by twill             #+#    #+#              #
#    Updated: 2019/04/15 21:36:48 by twill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
CFLAGS = -Wall -Wextra -Werror
HEADERS = fillit.h
LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft
SOURCE = main.c \
         ft_fillit.c \
		 ft_recursion.c \
		 ft_read_and_validate.c \
		 ft_fill_arr_shapes_and_get_size.c \
		 ft_arr_cleaner.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE_LIBFT)
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all fclean re clean
