/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 12:50:24 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 13:27:09 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_begin(t_pars *e, t_lex **node)
{
	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_begin_word;
	tools[VALUE] = &add_error_begin;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &add_error_begin;
	tools[(*node)->token_type](e, node);
}
