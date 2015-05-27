/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_inter_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:01:21 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 14:04:11 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_inter_word(t_pars *e, t_lex **node)
{

	char		*tmp;
	t_f_parse	tools[NBSUBSTEP];

	tools[SSPIGMENT] = &p_pigment;
	tools[SSSPHERE] = &p_sssphere;
	if (e->substep != SSBEGIN)
	{
		tools[e->substep](e, node);
		return ;
	}
	tmp = (*node)->value;
	if (!strcmp(tmp, "pigment"))
		e->substep = SSPIGMENT;
	else if (!strcmp(tmp, "sphere"))
		e->substep = SSSPHERE;
	else
		add_err(e, UNKOBJ, tmp);
}
