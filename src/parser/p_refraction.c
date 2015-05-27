/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_refraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:37:47 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 14:39:18 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					p_refraction(t_pars *e, t_lex **node)
{
	double		refraction;

	if (!(*node)->next)
		add_err(e, BADARG, "");
	else
		*node = (*node)->next;
	refraction = atof((*node)->value);
	if (refraction < 0 || refraction > 1)
		add_err(e, BADARG, (*node)->value);
	else
		e->cur->refraction = refraction;
}
