/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 10:29:57 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/15 13:39:15 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h> //

t_pix			**rotate_cam(t_libx	*mlx)
{
	int angle_x;
	int angle_y;
	int angle_z;
	t_vec vector_zero;
	t_point vector_point;
	t_vec real_vec_dir;
	t_vec vector_zero_norm;
	t_vec real_vec_dir_norm;
	// mlx->cam->dir pour vecteur direction de la cam, est faux;
	// mlx->cam->coord pour position de la cam;
	double dot;

	angle_x = 0;
	angle_y = 0;
	angle_z = 0;
	vector_zero.x = 500.0;
	vector_zero.y = 0.0;
	vector_zero.z = 0.0;

	vector_point.x = mlx->cam->dir.x;
	vector_point.y = mlx->cam->dir.y;
	vector_point.z = mlx->cam->dir.z;

	real_vec_dir = make_vec(vector_point, mlx->cam->coord); // le vrai vecteur de direction.

	ft_putchar('\n');
	ft_putchar('\n');
	printf("cam pos : %.4lfx, %.4lfy, %.4lfz,\ncam_vec_dir(look at) : %.4lfx, %.4lfy, %.4lfz,\nvect_zero : %.4lfx, %.4lfy, %.4lfz,\nreal cam_vec_dir : %.4lfx, %.4lfy, %.4lfz,\n",
		mlx->cam->coord.x, mlx->cam->coord.y, mlx->cam->coord.z,
		mlx->cam->dir.x, mlx->cam->dir.y, mlx->cam->dir.z,
		vector_zero.x, vector_zero.y, vector_zero.z,
		real_vec_dir.x, real_vec_dir.y, real_vec_dir.z);

	ft_putchar('\n');
	real_vec_dir_norm = normalize(real_vec_dir);
	vector_zero_norm = normalize(vector_zero);

	printf("vec_dir norm: %.4lfx, %.4lfy, %.4lfz\nvec_zero norm: %.4lfx, %.4lfy, %.4lfz\n", 
		real_vec_dir_norm.x, real_vec_dir_norm.y, real_vec_dir_norm.z,
		vector_zero_norm.x, vector_zero_norm.y, vector_zero_norm.z);

	dot = real_vec_dir_norm.x * vector_zero_norm.x + real_vec_dir_norm.y * vector_zero_norm.y;

	printf("dot x y = %lf, angle x y = %lf\n", dot,  180.0 * (acos(dot)) / M_PI);

	return (mlx->pix);
}