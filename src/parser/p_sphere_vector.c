/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sphere_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 14:30:04 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:41:07 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_sphere_vector(t_pars *e, t_lex **node)
{
	t_point	v;

	fill_vector(e, (*node)->value, (t_vec *)&v);
	if (e->cur)
		e->cur->coord = v;
}
