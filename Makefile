NAME = RT

SRCDIR = src

OBJDIR = obj

SRC = $(SRCDIR)/vecteur/norme.c\
	  $(SRCDIR)/vecteur/scalar.c\
	  $(SRCDIR)/vecteur/vector.c\
	  $(SRCDIR)/vecteur/make_vec.c\
	  $(SRCDIR)/vecteur/translate.c\
	  $(SRCDIR)/vecteur/vec_coef.c\
	  $(SRCDIR)/vecteur/vec_sum.c\
	  $(SRCDIR)/color/brightening.c\
	  $(SRCDIR)/color/color_diff.c\
	  $(SRCDIR)/color/color_sum.c\
	  $(SRCDIR)/color/darkening.c\
	  $(SRCDIR)/parser/parser.c\
	  $(SRCDIR)/parser/init_pars.c\
	  $(SRCDIR)/parser/check_line.c\
	  $(SRCDIR)/parser/add_err.c\
	  $(SRCDIR)/parser/p_begin.c\
	  $(SRCDIR)/parser/p_camera.c\
	  $(SRCDIR)/parser/check_pars_err.c\
	  $(SRCDIR)/error.c\
	  $(SRCDIR)/main.c

LIB =

OBJ = $(SRC:.c=.o)

CC = clang -g -O3 -Wall -Wextra -Werror -I include -I libft

all: lib $(NAME)

lib:
	make -C libft

.c.o:
	$(CC) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libft/libft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all re fclean
