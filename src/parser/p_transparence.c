/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_transparence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:20:47 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 14:23:05 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					p_transparence(t_pars *e, t_lex **node)
{
	double		transparence;

	if (!(*node)->next)
		add_err(e, BADARG, "");
	else
		*node = (*node)->next;
	transparence = atof((*node)->value);
	if (transparence < 0 || transparence > 1)
		add_err(e, BADARG, (*node)->value);
	else
		e->cur->transparence = transparence;

}
