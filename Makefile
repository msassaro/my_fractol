# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msassaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 11:33:54 by msassaro          #+#    #+#              #
#    Updated: 2016/03/02 14:26:14 by msassaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAG = -Wall -Wextra -Werror
FRMK = -framework OpenGL -framework AppKit
LIB = libft/libft.a mlx/libmlx.a
INCLUDES = -I libft/includes/libft.h -I mlx/mlx.h
SRC = \
clover_newton_bship_helios.c \
env_init_color.c \
event.c \
event2.c \
init_fract.c \
main.c \
mandelbrot_julia_jules_blob.c \
user_x.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@gcc $(FLAG) -c $(SRC) $(INCLUDES)
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(FRMK) $(LIB) $(INCLUDES)

%.oL %.c:
	gcc -O3 $(FLAG) -o $@ -c $^

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all fclean re
