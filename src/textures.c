/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 10:42:10 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/19 14:01:06 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>

void	texture_func(t_libx *mlx, t_pix *vec_dir) // norme a faire.
{
	t_point		inter_point;
	t_vec		normale;
	float		u;
	float		v;

	if (vec_dir->cur_obj == NULL)
		return ;
	inter_point = translate(mlx->cam->coord,
							vec_coef(vec_dir->pos_pix_vec, vec_dir->dist));
	if (vec_dir->cur_obj->type == SPHERE)
	{
		normale = normalize(make_vec(inter_point, vec_dir->cur_obj->coord));
		u = 0.5 + (atan2((-normale.x), (-normale.z)) / M_PI);
		v = 0.5 - asin((normale.y)) / M_PI;

		vec_dir->color->b = mlx->texture.data[(int)(u * mlx->texture.width)
		* mlx->texture.bpp + (int)(v * mlx->texture.height)
		* mlx->texture.size_line];

		vec_dir->color->g = mlx->texture.data[(int)(u * mlx->texture.width)
		* mlx->texture.bpp + (int)(v * mlx->texture.height) *
		mlx->texture.size_line + 1];

		vec_dir->color->r = mlx->texture.data[(int)(u * mlx->texture.width)
		* mlx->texture.bpp + (int)(v * mlx->texture.height) *
		mlx->texture.size_line + 2];

		set_color(mlx, vec_dir);
	}
}
