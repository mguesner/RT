/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_amb_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:35:20 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/14 15:00:00 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

void					cam_amb_light(t_pars *e, t_lex **node)
{
	double		ambient;

	if (!(*node)->next)
		add_err(e, BADARG, "");
	else
		*node = (*node)->next;
	ambient = atof((*node)->value);
	if (ambient < 0 || ambient > 1)
		add_err(e, BADARG, (*node)->value);
	else
		((t_camera *)e->cur)->ambient = ambient * 100;
}