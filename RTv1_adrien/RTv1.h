/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 13:04:52 by aleung-c          #+#    #+#             */
/*   Updated: 2015/04/28 17:01:37 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
#define RTV1_H

# include "./libft/libft.h"
# include <stdio.h> //
# include <math.h>
# include <mlx.h>
# define SCREEN_W 400
# define SCREEN_H 400

typedef struct s_pos
{
	double x;
	double y;
	double z;

}				t_pos;

typedef struct	s_rt 
{
	// MLX //
	void			*mlx;
	void			*win;
	void			*imgv;
	char			*img;
	int				bpp;
	int				sizeline;
	int				endian;

	// Ecran //
	int screen_width;
	int screen_height;

	//  Camera //
	double cam_x;
	double cam_y;
	double cam_z;

	double cam_angle_y;
	double cam_angle_x;
	double cam_angle_z; // pour rotation de la camera sur elle-meme.

	// sphere
	double sphere_x;
	double sphere_y;
	double sphere_z;
	double sphere_diam;
	double sphere_rad;

	double dist_cam_screen;

	// datas to save
	t_pos vp_center_pos;
	t_pos vp_up_pos;
	t_pos vp_upleft_pos;
	t_pos vp_right_pos;

	t_pos vp_pos; // pas utilise.
	t_pos vp_vectors[SCREEN_H * SCREEN_W];

}	t_rt;



#endif