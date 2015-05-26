/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reflex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 15:21:34 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/26 13:13:26 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	vec_reflex(t_pix *pix)
{
	t_vec	tmp;

	tmp = vec_sum(pix->pos_pix_vec, pix->normale);
	pix->reflex_vec = normalize(vec_sum(pix->normale, tmp));
}
