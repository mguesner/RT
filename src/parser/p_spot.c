/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_spot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:48:49 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:37:37 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_spot(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_spot_word;
	tools[VALUE] = &add_error_begin;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &p_sphere_vector;
	tools[(*node)->token_type](e, node);
}
