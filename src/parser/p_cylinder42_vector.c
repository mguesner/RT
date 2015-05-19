/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cylinder42_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:48:51 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/18 16:32:05 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <matrice.h>

void					p_cylinder42_vector(t_pars *e, t_lex **node)
{
	t_vec	v;
	t_vec	norm = {0, 0, 1};

	fill_vector(e, (*node)->value, &v);
	if (!e->nb_vector && e->cur)
		e->cur->coord = *((t_point *)&v);
	else if (e->cur)
	{
		v = normalize(v);
		((t_cylinder *)e->cur)->dir = v;
		t_vec	axe = vector(v, norm);
		printf("axe : (%f, %f, %f), cos de (%f, %f, %f) et (%f, %f, %f) : %f\n", axe.x, axe.y, axe.z,
			v.x, v.y, v.z, norm.x, norm.y, norm.z
			, scalar(v, norm));
		if (!axe.x && !axe.y && !axe.z)
		{
			((t_cylinder *)e->cur)->rot[0][0] = 1;
			((t_cylinder *)e->cur)->rot[1][1] = 1;
			((t_cylinder *)e->cur)->rot[2][2] = 1;
		}
		else
			get_rotate(axe, scalar(v, norm), ((t_cylinder *)e->cur)->rot);
		e->cur->coord = do_rotate(((t_cylinder *)e->cur)->rot, e->cur->coord);
		printf("Rot :\n\t(%f, %f, %f)\n\t(%f, %f, %f)\n\t(%f, %f, %f)\n"
			, ((t_cylinder *)e->cur)->rot[0][0], ((t_cylinder *)e->cur)->rot[1][0], ((t_cylinder *)e->cur)->rot[2][0]
			, ((t_cylinder *)e->cur)->rot[0][1], ((t_cylinder *)e->cur)->rot[1][1], ((t_cylinder *)e->cur)->rot[2][1]
			, ((t_cylinder *)e->cur)->rot[0][2], ((t_cylinder *)e->cur)->rot[1][2], ((t_cylinder *)e->cur)->rot[2][2]);
	}

	e->nb_vector++;
}
