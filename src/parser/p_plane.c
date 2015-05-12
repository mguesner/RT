/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 13:32:03 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 15:13:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_plane(char *line, t_pars *e, int *off)
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
	else if (e->substep == SSPIGMENT)
		p_pigment(line, e, off);
	else if (*(line + *off) == '<')
		plane_loc(line, e, off);
	else if (!ft_strncmp(line + *off, "pigment", (ret = 7)))
	{
		e->scope = CLOSE;
		e->substep = SSPIGMENT;
	}
	else
		add_err(e, UNKPARAM, line + *off);
	*off += ret;
}
