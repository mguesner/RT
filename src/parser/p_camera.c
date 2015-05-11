/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 15:32:16 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 17:35:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_camera(char *line, t_pars *e)
{
	if (!ft_strcmp(line, "}"))
	{
		e->scope = CLOSE;
		e->err = 0;
		e->step = PBEGIN;
		return ;
	}
	if (e->err)
		return ;
	if (e->scope == CLOSE)
		add_err(e, SCOPEMISS, line);
	else if (!ft_strncmp(line, "location", 8))
	{
		ft_strtrimbadass(line + 8);
		cam_loc(line + 8, e);
	}
	else
		add_err(e, UNKPARAM, line);
}
