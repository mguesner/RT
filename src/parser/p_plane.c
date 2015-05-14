/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 13:32:03 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 13:42:31 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_plane(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_plane_word;
	tools[VALUE] = &p_plane_value;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &p_plane_vector;
	tools[(*node)->token_type](e, node);
}
