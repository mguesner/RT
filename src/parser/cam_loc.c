/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_loc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 15:37:12 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:29:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					cam_loc(t_pars *e, t_lex **node)
{
	t_lex		*tmp;
	t_point		loc;

	ft_printf("cam_loc->");
	tmp = (*node)->next;
	if (!tmp || tmp->token_type != VECTOR)
		add_err(e, BADARG, tmp->value);
	else
	{
		*node = (*node)->next;
		fill_vector(e, tmp->value, (t_vec *)&loc);
		if (e->cur)
			e->cur->coord = loc;
	}
}
