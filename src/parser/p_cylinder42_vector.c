/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cylinder42_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 12:48:51 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 12:54:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_cylinder42_vector(t_pars *e, t_lex **node)
{
	t_vec	v;

	fill_vector(e, (*node)->value, &v);
	if (!e->nb_vector && e->cur)
		e->cur->coord = *((t_point *)&v);
	else if (e->cur)
		((t_cylinder *)e->cur)->dir = v;
	e->nb_vector++;
}
