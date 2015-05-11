/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_spot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:48:49 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 15:20:03 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_spot(char *line, t_pars *e, int *off)
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
	else if (*(line + *off) == '<')
		spot_loc(line, e, off);
	else if (!ft_strncmp(line + *off, "color rgb", (ret = 9)))
		spot_color(line + ret, e, off);
	else
		add_err(e, UNKPARAM, line + *off);
	*off += ret;
}
