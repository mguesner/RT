/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:13:06 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/26 14:59:01 by eruffieu         ###   ########.fr       */
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
# include <mlx.h>

# include <stdio.h>

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

typedef struct				s_texture
{
	int						exist;
	void					*imgv;
	char					*data;
	int						width;
	int						height;
	int						bpp;
	int						size_line;
	int						endian;
}							t_texture;

typedef struct				s_obj
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
}							t_obj;

typedef struct				s_camera
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	t_point					pix_hg;
	t_point					pix_bg;
	t_point					pix_hd;
	t_point					dir;
}							t_camera;

typedef struct				s_light
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
}							t_light;

typedef struct				s_plane
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	t_vec					norm;
}							t_plane;

typedef struct				s_sphere
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					radius;
}							t_sphere;

typedef struct				s_cylinder
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					radius;
	t_vec					dir;
}							t_cylinder;

typedef struct				s_cone
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
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
	int						pix_x;
	int						pix_y;
	double					dist;
	double					light_dist;
	double					shadow_dist;
	t_vec					pos_pix_vec;
	t_point					inter;
	t_color					*color;
	t_color					*color_specular;
	t_obj					*in_shadow;
	t_vec					normale;
	t_vec					reflex_vec;
	int						is_in_shadow;
	t_obj					*first_obj;
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
	int						current_pix;
	pthread_mutex_t			mutex;
	int						superint;
	t_camera				*cam;
	t_obj_list_begin		spots;
	t_obj_list_begin		obj;
	t_pix					**pix;
	t_texture				texture;
}							t_libx;

void						error(int errno);
void						mlx_struct_init(int width, int height, char *win_name, t_libx *mlx);
void						texture_func(t_pix *vec_dir);
void						start(t_libx *mlx);
double						touch(t_obj *obj, t_vec *vec, t_point *origine);
double						touch2(t_obj *obj, t_vec vec, t_point origine);
double						dist_sphere(t_sphere *sphere, t_vec *vec, t_point *o);
double						dist_plane(t_plane *plane, t_vec *vec, t_point *o);
double						dist_cone(t_cone *cone, t_vec *vec, t_point *o);
double						dist_cone2(t_cone *cone, t_vec vec, t_point o);
double						dist_cylinder(t_cylinder *cylinder, t_vec *vec, t_point *o);
double						dist_cylinder2(t_cylinder *cylinder, t_vec *vec, t_point o);
void						set_color_light(t_obj *light, t_pix *pix, t_point inter, int nb_spots);
void						calc_lum(t_libx *mlx, t_pix *vec_dir);
t_pix						**precalc_vec_cam(t_camera *cam);
void						inters(t_libx *mlx, int pix, int pix_x, int pix_y);
t_vec						get_normale(t_pix *pix, t_point inter);
void						set_color(t_libx *m, t_pix *pix, int spec_or_not);
void						antialiasing(t_libx *m);
void						apply_specular(t_libx *mlx, t_pix *pix);
void						vec_reflex(t_pix *pix);
void						key_rotate_cam(int keycode, t_libx *mlx);
void						key_translate_cam(int keycode, t_libx *mlx);

#endif
