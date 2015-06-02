/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_limit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 13:19:16 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 13:26:30 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					p_limit(t_pars *e, t_lex **node)
{
	if (!(*node)->next || (*node)->next->token_type != VALUE)
	{
		add_err(e, BADARG, "");
		return ;
	}
	*node = (*node)->next;
	e->cur->limite1 = atof((*node)->value);
	if (!(*node)->next)
	{
		add_err(e, BADARG, "");
		return ;
	}
	if ((*node)->next->token_type == VALUE)
	{
		*node = (*node)->next;
		e->cur->limite2 = atof((*node)->value);
	}
}
