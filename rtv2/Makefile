# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 08:37:57 by eruffieu          #+#    #+#              #
#    Updated: 2015/04/01 13:48:23 by eruffieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CC = gcc

CFLAGS = -framework OpenGL -framework AppKit -lmlx

SRC = rt.c lib_func.c parser.c parser2.c keyboard.c raytrace.c draw.c distances.c calc_lum.c

OBJ = $(SRC:.c=.o)

HEADER = rt.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -O3 $(OBJ) $(CFLAGS) -o $(NAME)
	make clean

%.o: %.c
	$(CC) -o $@ -c $< -I ./

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re %.o
