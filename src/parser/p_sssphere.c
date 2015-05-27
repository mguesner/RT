/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sssphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:05:22 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/27 15:16:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_sssphere(t_pars *e, t_lex **node)
{
	t_sphere	sphere;

	*node = (*node)->next;
	if ((*node)->token_type != OPENSCOPE)
		return ;
	*node = (*node)->next;
	while (*node && (*node)->token_type != CLOSESCOPE)
	{
		if ((*node)->token_type == VECTOR)
			fill_vector(e, (*node)->value, (t_vec *)&sphere.coord);
		*node = (*node)->next;
	}

}
