/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:47:02 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:17:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_plane_vector(t_pars *e, t_lex **node)
{
	t_vec	v;

	ft_printf("p_vector->");
	fill_vector(e, (*node)->value, &v);
	if (e->cur)
		((t_plane *)e->cur)->norm = v;
}
