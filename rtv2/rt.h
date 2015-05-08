/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 08:13:29 by eruffieu          #+#    #+#             */
/*   Updated: 2015/04/02 10:40:45 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_win;

typedef struct	s_obj
{
	char		*type;
	t_vector	*pos;
	t_vector	*angle;
	double		other;
	int			blue_color;
	int			green_color;
	int			red_color;
}				t_obj;

typedef struct	s_camera
{
	t_vector	*pos;
	t_vector	*pos_hg;
	t_vector	*pos_hd;
	t_vector	*pos_bg;
}				t_camera;

typedef struct	s_lst
{
	t_obj		*obj;
	void		*next;
}				t_lst;

typedef struct	s_all
{
	t_camera	*camera;
	t_lst		*list;
	t_lst		*list_spot;
	t_win		*libx;
	t_vector	*dir_vect_cam;
	t_vector	*rotation;
	t_lst		*first_obj;
	double		dist_spot;
	double		dist_max;
	int			x_pix;
	int			y_pix;
}				t_all;

void			init(t_all *c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
t_camera		*fill_camera(char *buffer, int *pos);
char			*find_num(char *buffer, int *pos);
void			parse(t_all *c, char *argv);
void			init(t_all *c);
void			do_key(int key, t_all *c);
void			raytrace(t_all *c);
double			dist_sphere(t_all *c, t_lst *temp);
double			dist_plan(t_all *c, t_lst *temp);
double			dist_cylinder(t_all *c, t_lst *temp);
double			dist_cone(t_all *c, t_lst *temp);
void			draw(t_all *c);
void			distrotion_vector(t_all *c, t_lst *temp);
double			calc_dist_spot(t_all *c);
void			check_run(t_all *c, t_lst *temp);

#endif
