NAME = RT

SRCDIR = src

OBJDIR = obj

SRC = $(SRCDIR)/vecteur/norme.c\
	  $(SRCDIR)/vecteur/scalar.c\
	  $(SRCDIR)/vecteur/vector.c\
	  $(SRCDIR)/vecteur/make_vec.c\
	  $(SRCDIR)/vecteur/translate.c\
	  $(SRCDIR)/vecteur/vec_coef.c\
	  $(SRCDIR)/vecteur/vec_sum.c

OBJ = $(SRC:.c=.o)

CC = clang -g -O3 -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all re fclean
