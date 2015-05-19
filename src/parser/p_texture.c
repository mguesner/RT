/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 14:28:42 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/19 15:09:01 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_texture(t_pars *e, t_lex **node)
{
	if (e->cur)
		e->cur->texture = texture_init(e, (*node)->value);
}
