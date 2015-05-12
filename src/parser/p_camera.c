/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 15:32:16 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 14:32:57 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_camera(char *line, t_pars *e, int *off)
{
	int		ret;

	if (!ft_strncmp(line + *off, "}", (ret = 1)))
	{
		e->scope = CLOSE;
		e->err = 0;
		e->step = PBEGIN;
		add_obj_lst(&e->obj_lst, e->cur);
	}
	else if (e->err)
		;
	else if (!ft_strncmp(line + *off, "{", (ret = 1)))
		e->scope = OPEN;
	else if (e->scope == CLOSE)
		add_err(e, SCOPEMISS, line + *off);
	else if (!ft_strncmp(line + *off, "location", (ret = 8)))
		cam_loc(line + ret, e, off);
	else if (!ft_strncmp(line + *off, "look_at", (ret = 7)))
		cam_look_at(line + ret, e, off);
	else
		add_err(e, UNKPARAM, line + *off);
	*off += ret;
}