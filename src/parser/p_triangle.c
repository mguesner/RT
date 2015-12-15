/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 12:55:30 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 12:55:43 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_triangle(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_plane_word;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &p_triangle_vector;
	tools[(*node)->token_type](e, node);
}
