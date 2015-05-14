/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_closescope.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:37:10 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 12:50:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_closescope(t_pars *e, t_lex **node)
{
	if (e->scope > 0)
		e->scope--;
	else
		add_err(e, SCOPEMISS, (*node)->value);
	if (!e->scope && e->cur)
	{
		add_obj_lst(&e->obj_lst, e->cur);
		e->cur = NULL;
	}
	if (!e->scope)
	{
		e->nb_vector = 0;
		e->nb_value = 0;
		e->step = PBEGIN;
	}
	if (e->scope == 1)
		e->substep = SSBEGIN;
	e->err = 0;
}
