/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:13:06 by mguesner          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/05/11 16:00:08 by eruffieu         ###   ########.fr       */
=======
/*   Updated: 2015/05/11 14:24:34 by mguesner         ###   ########.fr       */
>>>>>>> db58c72cbc1f81cc98458752262fad005ed755d5
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIDTH 1920
# define HEIGHT 1080
# define TOTAL_PIX WIDTH * HEIGHT

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
<<<<<<< HEAD
	t_point					pix_hg;
	t_point					pix_bg;
	t_point					pix_hd;
=======
	t_vec					dir;
>>>>>>> db58c72cbc1f81cc98458752262fad005ed755d5
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
	int						radius;
}							t_sphere;

typedef struct				s_cylinder
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	t_vec					dir;
	int						radius;
}							t_cylinder;

typedef struct				s_cone
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	int						angle;
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
	t_vec					*pos_all_pix;
}							t_libx;

void						error(int errno);
t_libx						*mlx_struct_init(int width, int height, char *win_name);
void						set_pixel_to_img(t_libx *m, int pix_x, int pix_y, t_color *color);
void						start(t_libx *mlx);
t_vec						*precalc_vec_cam(t_camera *cam);
double						dist_sphere(t_libx *mlx, int pix_x, int pix_y);

#endif
