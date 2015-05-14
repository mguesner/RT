/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cone42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 13:05:26 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 13:06:30 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_cone42(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_plane_word;
	tools[VALUE] = &p_sphere_value;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &p_cylinder42_vector;
	tools[(*node)->token_type](e, node);
}
