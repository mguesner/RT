/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_camera_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:35:20 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 15:00:00 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_camera_word(t_pars *e, t_lex **node)
{
	char	*tmp;

	tmp = (*node)->value;
	if (!strcmp(tmp, "location"))
		cam_loc(e, node);
	else if (!strcmp(tmp, "look_at"))
		cam_look_at(e, node);
	else if (!strcmp(tmp, "ambient_light"))
		cam_amb_light(e, node);
	else
		add_err(e, UNKOBJ, tmp);
}
