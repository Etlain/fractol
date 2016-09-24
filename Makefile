# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/09/24 17:01:55 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = libft/libft.a

SRC = main.c hook.c fractal.c put_pixel.c init_fract.c key_hook.c

PATH_SRC = sources/

FLAGS = -Wall -Wextra -Werror

LIBFT = -C libft/

MINILIB = -C minilibx_macos/

ML = minilibx_macos/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

all: 
	make $(LIBFT)
	make $(MINILIB)
	gcc -o $(NAME) $(addprefix $(PATH_SRC), $(SRC)) $(LIB) $(ML) $(FRAMEWORK)

clean :
	make clean $(LIBFT)
	make clean $(MINILIB)

fclean:
	make fclean $(LIBFT)
	make clean $(MINILIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
