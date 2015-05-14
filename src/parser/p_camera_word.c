/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_camera_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:35:20 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 16:06:04 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_camera_word(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	ft_printf("p_camera_word->%s->", tmp);
	if (!strcmp(tmp, "location"))
		cam_loc(e, node);
	else if (!strcmp(tmp, "look_at"))
		cam_look_at(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}
