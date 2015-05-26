/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:49:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/26 14:14:41 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdio.h>

void	specular2(double my_dot, t_pix *pix)
{
	int		tmp_r;
	int		tmp_g;
	int		tmp_b;
	double	coef;

	tmp_r = 255 - pix->color_specular->r;
	tmp_g = 255 - pix->color_specular->g;
	tmp_b = 255 - pix->color_specular->b;
	coef = (1 - (0.99 - my_dot) * (1 / 0.04));
	pix->color_specular->r += tmp_r * coef;
	pix->color_specular->b += tmp_b * coef;
	pix->color_specular->g += tmp_g * coef;
}

void	apply_specular(t_libx *mlx, t_pix *pix)
{
	t_vec		incom_vector;
	double		my_dot;
	t_obj_list	*lights;

	lights = mlx->spots.begin;
	pix->color_specular->r = pix->color->r;
	pix->color_specular->b = pix->color->b;
	pix->color_specular->g = pix->color->g;
	while (lights)
	{
		incom_vector = normalize(make_vec(lights->obj->coord, pix->inter));
		my_dot = scalar(incom_vector, pix->reflex_vec);
		if (my_dot > 0.95 && my_dot <= 0.99)
			specular2(my_dot, pix);
		else if (my_dot > 0.99)
		{
			pix->color_specular->r = 255;
			pix->color_specular->b = 255;
			pix->color_specular->g = 255;
		}
		lights = lights->next;
	}
}
