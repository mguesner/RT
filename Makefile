NAME = RT

SRCDIR = src

OBJDIR = obj

SRC = $(SRCDIR)/vecteur/norme.c\
	  $(SRCDIR)/vecteur/scalar.c\
	  $(SRCDIR)/vecteur/vector.c\
	  $(SRCDIR)/vecteur/make_vec.c\
	  $(SRCDIR)/vecteur/translate.c\
	  $(SRCDIR)/vecteur/normalize.c\
	  $(SRCDIR)/vecteur/vec_coef.c\
	  $(SRCDIR)/vecteur/vec_sum.c\
	  $(SRCDIR)/vecteur/pointcpy.c\
	  $(SRCDIR)/color/brightening.c\
	  $(SRCDIR)/color/color_diff.c\
	  $(SRCDIR)/color/color_sum.c\
	  $(SRCDIR)/color/darkening.c\
	  $(SRCDIR)/parser/lex_pars.c\
	  $(SRCDIR)/parser/lexer.c\
	  $(SRCDIR)/parser/add_lex_node.c\
	  $(SRCDIR)/parser/lex_word.c\
	  $(SRCDIR)/parser/lex_value.c\
	  $(SRCDIR)/parser/lex_vec.c\
	  $(SRCDIR)/parser/parser.c\
	  $(SRCDIR)/parser/fill_vector.c\
	  $(SRCDIR)/parser/p_closescope.c\
	  $(SRCDIR)/parser/p_openscope.c\
	  $(SRCDIR)/parser/p_damier.c\
	  $(SRCDIR)/parser/p_begin.c\
	  $(SRCDIR)/parser/p_begin_word.c\
	  $(SRCDIR)/parser/add_error_begin.c\
	  $(SRCDIR)/parser/p_camera.c\
	  $(SRCDIR)/parser/p_camera_word.c\
	  $(SRCDIR)/parser/cam_loc.c\
	  $(SRCDIR)/parser/cam_amb_light.c\
	  $(SRCDIR)/parser/p_pigment.c\
	  $(SRCDIR)/parser/p_texture.c\
	  $(SRCDIR)/parser/p_finish.c\
	  $(SRCDIR)/parser/p_specular.c\
	  $(SRCDIR)/parser/p_reflection.c\
	  $(SRCDIR)/parser/p_transparence.c\
	  $(SRCDIR)/parser/p_refraction.c\
	  $(SRCDIR)/parser/cam_look_at.c\
	  $(SRCDIR)/parser/add_error_camera.c\
	  $(SRCDIR)/parser/p_plane.c\
	  $(SRCDIR)/parser/p_plane_value.c\
	  $(SRCDIR)/parser/p_plane_word.c\
	  $(SRCDIR)/parser/p_plane_vector.c\
	  $(SRCDIR)/parser/p_sphere.c\
	  $(SRCDIR)/parser/p_sphere_value.c\
	  $(SRCDIR)/parser/p_sphere_vector.c\
	  $(SRCDIR)/parser/spot_color.c\
	  $(SRCDIR)/parser/p_spot.c\
	  $(SRCDIR)/parser/p_limit.c\
	  $(SRCDIR)/parser/p_spot_word.c\
	  $(SRCDIR)/parser/add_obj_lst.c\
	  $(SRCDIR)/parser/init_pars.c\
	  $(SRCDIR)/parser/clean_parse.c\
	  $(SRCDIR)/parser/add_err.c\
	  $(SRCDIR)/parser/p_cylinder42.c\
	  $(SRCDIR)/parser/p_cylinder42_vector.c\
	  $(SRCDIR)/parser/p_cone42.c\
	  $(SRCDIR)/parser/p_intersection.c\
	  $(SRCDIR)/parser/p_inter_word.c\
	  $(SRCDIR)/parser/p_sssphere.c\
	  $(SRCDIR)/parser/p_triangle.c\
	  $(SRCDIR)/parser/p_triangle_vector.c\
	  $(SRCDIR)/parser/check_pars_err.c\
	  $(SRCDIR)/matrice/get_rotate.c\
	  $(SRCDIR)/matrice/do_rotate.c\
	  $(SRCDIR)/matrice/inverse_rot.c\
	  $(SRCDIR)/matrice/do_rotate_vec.c\
	  $(SRCDIR)/error.c\
	  $(SRCDIR)/main.c\
	  $(SRCDIR)/menu_rt.c\
	  $(SRCDIR)/cd_custom.c\
	  $(SRCDIR)/clean_mlx.c\
	  $(SRCDIR)/touch.c\
	  $(SRCDIR)/light.c\
	  $(SRCDIR)/light2.c\
	  $(SRCDIR)/sphere.c\
	  $(SRCDIR)/plane.c\
	  $(SRCDIR)/inters.c\
	  $(SRCDIR)/antialiasing.c\
	  $(SRCDIR)/boucle_princ.c\
	  $(SRCDIR)/precalc_vec_cam.c\
	  $(SRCDIR)/cone.c\
	  $(SRCDIR)/cylinder.c\
	  $(SRCDIR)/set_color_light.c\
	  $(SRCDIR)/textures_init.c\
	  $(SRCDIR)/textures.c\
	  $(SRCDIR)/get_normale.c\
	  $(SRCDIR)/specular.c\
	  $(SRCDIR)/vec_reflex.c\
	  $(SRCDIR)/interaction.c\
	  $(SRCDIR)/triangle.c\
	  $(SRCDIR)/set_color_finish.c\
	  $(SRCDIR)/do_raytracing.c\
	  $(SRCDIR)/mlx_init.c\
	  $(SRCDIR)/cell.c\
	  $(SRCDIR)/blur.c\
	  $(SRCDIR)/sepia.c\
	  $(SRCDIR)/damier.c\
	  $(SRCDIR)/bitmap.c\
	  $(SRCDIR)/norm_maping.c\
	  $(SRCDIR)/perlin.c\
	  $(SRCDIR)/perlin_calc.c

LIB =

OBJ = $(SRC:.c=.o)

CC = clang -g -O3 -Wall -Wextra -Werror -I include -I libft

all: lib $(NAME)

lib:
	make -C libft

.c.o:
	$(CC) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all re fclean
