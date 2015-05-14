/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_look_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:00:13 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:08:35 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					cam_look_at(t_pars *e, t_lex **node)
{
	t_lex		*tmp;
	t_vec		dir;

	ft_printf("cam_look_at->");
	tmp = (*node)->next;
	if (!tmp || tmp->token_type != VECTOR)
		add_err(e, BADARG, tmp->value);
	else
	{
		*node = (*node)->next;
		fill_vector(e, tmp->value, &dir);
		((t_camera *)e->cur)->dir = dir;
	}
}
