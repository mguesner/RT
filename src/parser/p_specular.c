/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specular.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 11:29:47 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/26 13:29:12 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					p_specular(t_pars *e, t_lex **node)
{
	double		specular;

	if (!((*node)->next))
		add_err(e, BADARG, "");
	else
	{
		*node = (*node)->next;
		specular = atof((*node)->value);
		if (specular < 0 || specular > 1)
			add_err(e, BADARG, (*node)->value);
		else
			e->cur->specular = specular;
	}
}
