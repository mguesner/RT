/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_loc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 15:37:12 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 14:32:00 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					cam_loc(t_pars *e, t_lex **node)
{
	t_lex		*tmp;
	t_point		loc;

	tmp = (*node)->next;
	if (!tmp || tmp->token_type != VECTOR)
		add_err(e, BADARG, tmp->value);
	else
	{
		*node = (*node)->next;
		if (!fill_vector(e, tmp->value, (t_vec *)&loc))
			return ;
		if (e->cur)
			e->cur->coord = loc;
	}
}
