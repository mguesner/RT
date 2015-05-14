/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 14:25:29 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:45:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_plane_word(t_pars *e, t_lex **node)
{
	char		*tmp;
	t_f_parse	tools[NBSUBSTEP];

	tools[SSPIGMENT] = &p_pigment;
	if (e->substep != SSBEGIN)
	{
		tools[e->substep](e, node);
		return ;
	}
	tmp = (*node)->value;
	if (!strcmp(tmp, "pigment"))
		e->substep = SSPIGMENT;
	else
		add_err(e, UNKOBJ, (*node)->value);
}
