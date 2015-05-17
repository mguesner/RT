/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_look_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:00:13 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/15 15:07:23 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					cam_look_at(t_pars *e, t_lex **node)
{
	t_lex		*tmp;
	t_point		dir;

	tmp = (*node)->next;
	if (!tmp || tmp->token_type != VECTOR)
		add_err(e, BADARG, tmp->value);
	else
	{
		*node = (*node)->next;
		fill_vector(e, tmp->value, (t_vec *)&dir);
		((t_camera *)e->cur)->dir = dir;
	}
}
