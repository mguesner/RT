/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_triangle_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:55:27 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 12:55:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_triangle_vector(t_pars *e, t_lex **node)
{
	t_vec	v;

	fill_vector(e, (*node)->value, &v);
	if (!e->nb_vector && e->cur)
		e->cur->coord = *((t_point *)&v);
	else if (e->nb_vector == 1 && e->cur)
		((t_triangle *)e->cur)->u = *(&v);
	else if (e->cur)
		((t_triangle *)e->cur)->v = *(&v);
	e->nb_vector++;
}
