/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:43:31 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 13:46:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					p_plane_value(t_pars *e, t_lex **node)
{
	t_point	p;

	if (e->substep != SSBEGIN)
	{
		add_err(e, UNKOBJ, (*node)->value);
		return ;
	}
	p.z = atof((*node)->value);
	e->cur->coord = p;
}
