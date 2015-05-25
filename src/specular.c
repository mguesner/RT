/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:49:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/25 15:04:16 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdio.h>


void	apply_specular(t_libx *mlx, t_pix *pix)
{
	t_vec	incomVector;
	float	myDot;
	t_obj_list	*lights;
	lights = mlx->spots.begin;
	pix->color_specular->r = pix->color->r;
	pix->color_specular->b = pix->color->b;
	pix->color_specular->g = pix->color->g;
	while (lights)
	{
		incomVector = normalize(make_vec(lights->obj->coord, pix->inter));
		myDot = scalar(incomVector, pix->reflex_vec);
		if (myDot > 0.9 && myDot <= 0.99)
		{
			int		tmp_r = 255 - pix->color_specular->r;
			int		tmp_g = 255 - pix->color_specular->g;
			int		tmp_b = 255 - pix->color_specular->b;
			double prout = (1 - (0.99 - myDot) * (1 / 0.09));
			pix->color_specular->r += tmp_r * prout;
			pix->color_specular->b += tmp_b * prout;
			pix->color_specular->g += tmp_g * prout;
		}
		else if (myDot > 0.99)
		{
			pix->color_specular->r = 255;
			pix->color_specular->b = 255;
			pix->color_specular->g = 255;
		}
		lights = lights->next;
	}
}
