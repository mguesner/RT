/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:13:06 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 18:08:47 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <vecteur.h>
# include <color.h>
# include <libft.h>
# include "../minilibx_macos/mlx.h"
#

typedef enum				e_obj_type
{
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
}							t_camera;

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
}							t_libx;

void						error(int errno);
t_libx						*mlx_struct_init(int width, int height, char *win_name);
void						set_pixel_to_img(t_libx *m, int pix_x, int pix_y, t_color *color);

#endif
