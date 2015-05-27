/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_intersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 13:57:53 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 15:04:03 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_intersection(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_inter_word;
	tools[VALUE] = &add_error_camera;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &add_error_camera;
	tools[(*node)->token_type](e, node);
}
