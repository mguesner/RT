/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:49:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/22 15:45:26 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdio.h>

// t_color	mult_color(t_color c, float f)
// {
// 	t_color newc;

// 	newc.r = ((float)c.r * f);
// 	newc.g = ((float)c.g * f);
// 	newc.b = ((float)c.b * f);
// 	return (newc);
// }

// t_color set_max(t_color c)
// {
// 	if (c.r < 0)
// 		c.r = 0;
// 	if (c.r > 255)
// 		c.r = 255;
// 	if (c.g < 0)
// 		c.g = 0;
// 	if (c.g > 255)
// 		c.g = 255;
// 	if (c.b < 0)
// 		c.b = 0;
// 	if (c.b > 255)
// 		c.b = 255;
// 	return (c);
// }

// float MAX(float scalar, float other)
// {
// 	if (scalar > other)
// 		return (scalar);
// 	return (other);
// }

void	apply_specular(t_libx *mlx, t_pix *pix)
{
	t_vec	incomVector;
	// t_vec	incomVectorN;
	float	myDot;
	// float	myLen;
	// t_vec	tempNormal;
	// t_vec	reflectVector;
	// t_vec	reflectVectorN;
	// float	mySpec;
	t_obj_list	*lights;
	// t_color	specularColor;
	// t_color	pix_color;

	// pix_color.r = pix->color->r;
	// pix_color.b = pix->color->b;
	// pix_color.g = pix->color->g;
	lights = mlx->spots.begin;
	// specularColor.r = 255;
	// specularColor.g = 255;
	// specularColor.b = 255;
	while (lights)
	{
		incomVector = normalize(make_vec(lights->obj->coord, pix->inter));
		// incomVectorN = normalize(incomVector);
		// reflectVector = vec_sum(incomVectorN, pix->normale);
		myDot = acos(scalar(incomVector, pix->reflex_vec));
		if ((myDot > -1.45 && myDot < 1.45) ||
			(myDot > -0.55 && myDot < 0.55))
		{
			pix->color->r = 255;
			pix->color->b = 255;
			pix->color->g = 255;
		}
		// myDot = -scalar(incomVectorN, pix->normale);
		// myLen = 2.0 * myDot;
		// tempNormal = vec_coef(pix->normale, myLen);
		// reflectVector  = vec_sum(tempNormal, incomVectorN);
		// reflectVectorN = normalize(reflectVector);
		// mySpec = MAX(-scalar(reflectVectorN, incomVectorN), 0.0);
		// mySpec = powf(mySpec, 5);
		// specularColor = mult_color(specularColor, mySpec);
		// pix_color = color_sum(pix_color, specularColor);
		// pix_color = set_max(pix_color);
		lights = lights->next;
		// pix->color->r = pix_color.r;
		// pix->color->b = pix_color.b;
		// pix->color->g = pix_color.g;
	}
}
