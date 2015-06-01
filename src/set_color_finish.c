/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 16:58:02 by eruffieu          #+#    #+#             */
/*   Updated: 2015/06/01 17:05:45 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdio.h>
#include <matrice.h>

void	set_finish_reflection_one(t_pix *vec_dir)
{
	vec_dir->color->b = vec_dir->cur_obj->color.b *
	(1.0 - vec_dir->first_obj->reflection);
	if (vec_dir->color->b > 255)
		vec_dir->color->b = 255;
	else if (vec_dir->color->b < 0)
		vec_dir->color->b = 0;
	vec_dir->color->g =  vec_dir->cur_obj->color.g *
	(1.0 - vec_dir->first_obj->reflection);
	if (vec_dir->color->g > 255)
		vec_dir->color->g = 255;
	else if (vec_dir->color->g < 0)
		vec_dir->color->g = 0;
	vec_dir->color->r =  vec_dir->cur_obj->color.r *
	(1.0 - vec_dir->first_obj->reflection);
	if (vec_dir->color->r > 255)
		vec_dir->color->r = 255;
	else if (vec_dir->color->r < 0)
		vec_dir->color->r = 0;
}

void	set_finish_transparence_one(t_pix *vec_dir)
{
	vec_dir->color->b = vec_dir->cur_obj->color.b *
	(1.0 - vec_dir->first_obj->transparence);
	if (vec_dir->color->b > 255)
		vec_dir->color->b = 255;
	else if (vec_dir->color->b < 0)
		vec_dir->color->b = 0;
	vec_dir->color->g =  vec_dir->cur_obj->color.g *
	(1.0 - vec_dir->first_obj->transparence);
	if (vec_dir->color->g > 255)
		vec_dir->color->g = 255;
	else if (vec_dir->color->g < 0)
		vec_dir->color->g = 0;
	vec_dir->color->r =  vec_dir->cur_obj->color.r *
	(1.0 - vec_dir->first_obj->transparence);
	if (vec_dir->color->r > 255)
		vec_dir->color->r = 255;
	else if (vec_dir->color->r < 0)
		vec_dir->color->r = 0;
}

void	set_finish_transparence(t_pix *vec_dir)
{
	vec_dir->color->b = vec_dir->cur_obj->color.b *
	(vec_dir->first_obj->transparence) +
	vec_dir->first_obj->color.b *
	(1.0 - vec_dir->first_obj->transparence);
	if (vec_dir->color->b > 255)
		vec_dir->color->b = 255;
	else if (vec_dir->color->b < 0)
		vec_dir->color->b = 0;
	vec_dir->color->g = vec_dir->cur_obj->color.g *
	(vec_dir->first_obj->transparence)
	+ vec_dir->first_obj->color.g *
	(1.0 - vec_dir->first_obj->transparence);
	if (vec_dir->color->g > 255)
		vec_dir->color->g = 255;
	else if (vec_dir->color->g < 0)
		vec_dir->color->g = 0;
	vec_dir->color->r = vec_dir->cur_obj->color.r *
	(vec_dir->first_obj->transparence)
	+ vec_dir->first_obj->color.r *
	(1.0 - vec_dir->first_obj->transparence);
	if (vec_dir->color->r > 255)
		vec_dir->color->r = 255;
	else if (vec_dir->color->r < 0)
		vec_dir->color->r = 0;
}

void	set_finish_reflection(t_pix *vec_dir)
{
	vec_dir->color->b = vec_dir->cur_obj->color.b +
	vec_dir->first_obj->color.b
	* (1.0 - vec_dir->first_obj->reflection);
	if (vec_dir->color->b > 255)
		vec_dir->color->b = 255;
	else if (vec_dir->color->b < 0)
		vec_dir->color->b = 0;
	vec_dir->color->g = vec_dir->cur_obj->color.g +
	vec_dir->first_obj->color.g *
	(1.0 - vec_dir->first_obj->reflection);
	if (vec_dir->color->g > 255)
		vec_dir->color->g = 255;
	else if (vec_dir->color->g < 0)
		vec_dir->color->g = 0;
	vec_dir->color->r = vec_dir->cur_obj->color.r +
	vec_dir->first_obj->color.r *
	(1.0 - vec_dir->first_obj->reflection);
	if (vec_dir->color->r > 255)
		vec_dir->color->r = 255;
	else if (vec_dir->color->r < 0)
		vec_dir->color->r = 0;
}

void	set_original(t_pix *vec_dir)
{
	vec_dir->color->b = vec_dir->cur_obj->color.b;
	vec_dir->color->g = vec_dir->cur_obj->color.g;
	vec_dir->color->r = vec_dir->cur_obj->color.r;
}
