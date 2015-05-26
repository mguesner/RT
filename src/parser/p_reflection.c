/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_reflection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 12:31:49 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/26 14:00:10 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					p_reflection(t_pars *e, t_lex **node)
{
	double		reflection;

	if (!(*node)->next)
		add_err(e, BADARG, "");
	else
		*node = (*node)->next;
	reflection = atof((*node)->value);
	if (reflection < 0 || reflection > 1)
		add_err(e, BADARG, (*node)->value);
	else
		e->cur->reflection = reflection;
}
