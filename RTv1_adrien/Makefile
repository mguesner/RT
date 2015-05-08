# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/21 14:52:17 by aleung-c          #+#    #+#              #
#    Updated: 2015/04/21 16:29:58 by aleung-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

HEADER = RTv1.h

SRC = RTv1.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/

MLX = -L/usr/X11/lib -lmlx -framework AppKit -framework OpenGL

CC = gcc -g -Wall -Werror -Wextra -Ofast 

all : Lib $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft/ -lft $(MLX)

Lib :
	make -C $(LIB)

clean :
	rm -rf $(OBJ)
	cd $(LIB) ; make clean

fclean : clean
	rm -rf $(NAME)
	cd $(LIB) ; make fclean

re : fclean all

.PHONY : all clean fclean re