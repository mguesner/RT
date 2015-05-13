/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:13:06 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 13:07:38 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIDTH 1920
# define HEIGHT 1080
# define TOTAL_PIX WIDTH * HEIGHT
# define EPSILON 0.1E-7

# include <vecteur.h>
# include <color.h>
# include <libft.h>
# include "../minilibx_macos/mlx.h"

typedef enum				e_obj_type
{
	CAM,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	NBOBJTYPE
}							t_obj_type;

typedef struct				s_obj
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
}							t_obj;

typedef struct				s_camera
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	t_point					pix_hg;
	t_point					pix_bg;
	t_point					pix_hd;
	t_vec					dir;
}							t_camera;

typedef struct				s_light
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
}							t_light;

typedef struct				s_plane
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	t_vec					norm;
}							t_plane;

typedef struct				s_sphere
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					radius;
}							t_sphere;

typedef struct				s_cylinder
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	t_vec					dir;
	double					radius;
}							t_cylinder;

typedef struct				s_cone
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					angle;
	t_vec					dir;
}							t_cone;

typedef struct				s_obj_list
{
	t_obj					*obj;
	struct s_obj_list		*next;
}							t_obj_list;

typedef struct				s_obj_list_begin
{
	t_obj_list				*begin;
	t_obj_list				*end;
	int						size;
}							t_obj_list_begin;

typedef struct				s_pix
{
	t_obj					*cur_obj;
	double					dist;
	t_vec					*pos_pix_vec;
}							t_pix;

typedef struct				s_libx
{
	void					*window;
	void					*mlx;
	void					*img;
	char					*data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	t_obj_list_begin		*obj;
	t_camera				*cam;
	t_pix					*pix;
}							t_libx;

void						error(int errno);
t_libx						*mlx_struct_init(int width, int height, char *win_name);
void						set_pixel_to_img(t_libx *m, int pix_x, int pix_y, t_color *color);
void						start(t_libx *mlx);
t_vec						*precalc_vec_cam(t_camera *cam);
double						touch(t_obj *obj, t_vec *vec, t_point *origine);
double						dist_sphere(t_sphere *sphere, t_vec *vec, t_point *o);
void						antialiasing(t_libx *m);
double						dist_plane(t_plane *plane, t_vec *vec, t_point *o);
double						dist_cone(t_cone *cone, t_vec *vec, t_point *o);

#endif
