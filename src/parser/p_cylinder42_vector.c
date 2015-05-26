/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cylinder42_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:48:51 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/26 14:09:35 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <matrice.h>

void					create_norm(t_vec *norm)
{
	norm->x = 0;
	norm->y = 0;
	norm->z = 1;
}

void					p_cylinder42_vector(t_pars *e, t_lex **node)
{
	t_vec	v;
	t_vec	norm;
	t_vec	axe;

	create_norm(&norm);
	fill_vector(e, (*node)->value, &v);
	if (!e->nb_vector && e->cur)
		e->cur->coord = *((t_point *)&v);
	else if (e->cur)
	{
		v = normalize(v);
		((t_cylinder *)e->cur)->dir = v;
		axe = vector(v, norm);
		if (!axe.x && !axe.y && !axe.z)
		{
			((t_cylinder *)e->cur)->rot[0][0] = 1;
			((t_cylinder *)e->cur)->rot[1][1] = 1;
			((t_cylinder *)e->cur)->rot[2][2] = 1;
		}
		else
			get_rotate(axe, scalar(v, norm), ((t_cylinder *)e->cur)->rot);
		e->cur->coord = do_rotate(((t_cylinder *)e->cur)->rot, e->cur->coord);
	}
	e->nb_vector++;
}
