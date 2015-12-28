/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_openscope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:39:33 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/15 14:26:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_openscope(t_pars *e, t_lex **node)
{
	if (e->step == PBEGIN)
		add_err(e, SCOPEMISS, (*node)->value);
	e->scope++;
	if (e->scope > 2)
		add_err(e, SCOPEMISS, (*node)->value);
}
