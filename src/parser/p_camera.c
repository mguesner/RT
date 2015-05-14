/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 15:32:16 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 13:26:10 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_camera(t_pars *e, t_lex **node)
{

	t_fptoken		tools[NBTOKEN];

	tools[WORD] = &p_camera_word;
	tools[VALUE] = &add_error_camera;
	tools[OPENSCOPE] = &p_openscope;
	tools[CLOSESCOPE] = &p_closescope;
	tools[VECTOR] = &add_error_camera;
	tools[(*node)->token_type](e, node);
}
