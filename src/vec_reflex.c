/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reflex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 15:21:34 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/22 16:30:00 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	vec_reflex(t_pix *pix)
{
	t_vec	tmp;

	tmp = vec_sum(pix->pos_pix_vec, pix->normale);
	pix->reflex_vec = normalize(vec_sum(pix->normale, tmp));
	// printf("(%f, %f, %f)(%f) + (%f, %f, %f)(%f) = (%f, %f, %f)(%f)\n"
	// 	, pix->pos_pix_vec.x, pix->pos_pix_vec.y, pix->pos_pix_vec.z, norme(pix->pos_pix_vec)
	// 	, pix->normale.x, pix->normale.y, pix->normale.z, norme(pix->normale)
	// 	, pix->reflex_vec.x, pix->reflex_vec.y, pix->reflex_vec.z, norme(pix->reflex_vec));
}
