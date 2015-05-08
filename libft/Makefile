# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 11:03:38 by mguesner          #+#    #+#              #
#    Updated: 2014/06/25 14:23:55 by mguesner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = ft_isprint.o \
	  ft_memset.o \
	  ft_strcat.o \
	  ft_striteri.o \
	  ft_strnequ.o \
	  ft_toupper.o \
	  ft_itoa.o \
	  ft_putchar.o \
	  ft_strchr.o \
	  ft_strjoin.o \
	  ft_strnew.o \
	  ft_memalloc.o \
	  ft_putchar_fd.o \
	  ft_strclr.o \
	  ft_strlcat.o \
	  ft_strnstr.o \
	  ft_atoi.o \
	  ft_memccpy.o \
	  ft_putendl.o \
	  ft_strcmp.o \
	  ft_strlen.o \
	  ft_strrchr.o \
	  ft_bzero.o \
	  ft_memchr.o \
	  ft_putendl_fd.o \
	  ft_strcpy.o \
	  ft_strmap.o \
	  ft_strsplit.o \
	  ft_isalnum.o \
	  ft_memcmp.o \
	  ft_putnbr.o \
	  ft_strdel.o \
	  ft_strmapi.o \
	  ft_strstr.o \
	  ft_isalpha.o \
	  ft_memcpy.o \
	  ft_putnbr_fd.o \
	  ft_strdup.o \
	  ft_strncat.o \
	  ft_strsub.o \
	  ft_isascii.o \
	  ft_memdel.o \
	  ft_putstr.o \
	  ft_strequ.o \
	  ft_strncmp.o \
	  ft_strtrim.o \
	  ft_isdigit.o \
	  ft_memmove.o \
	  ft_putstr_fd.o \
	  ft_striter.o \
	  ft_strncpy.o \
	  ft_tolower.o \
	  ft_power.o \
	  ft_max.o \
	  ft_min.o \
	  ft_isblank.o \
	  ft_addchar.o \
	  get_next_line.o \
	  ft_strtrimbadass.o \
	  ft_strtrijoin.o \
	  ft_strcut.o \
	  ft_strsplit2.o \
	  ft_printf.o \
	  ft_is_flag.o \
	  ft_nputnbr.o \
	  ft_nputstr.o \
	  ft_nputunbr.o \
	  ft_put_flag01.o \
	  ft_puto.o \
	  ft_count_digit.o \
	  ft_put_flag20.o \
	  ft_put_flag_ro.o \
	  ft_put_flag30.o \
	  ft_put_flag_c.o \
	  ft_put_flag_u.o \
	  ft_skip.o \
	  ft_putx.o \
	  ft_putp.o \
	  ft_put_flag_x.o \
	  ft_put_flag_point_star.o \
	  ft_tabdel.o

CC = gcc -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rs $(NAME) $(OBJ)
	ranlib $(NAME)

%o: %.c
	$(CC) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean all re fclean
