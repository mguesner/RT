/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 12:50:24 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 17:12:04 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void				p_begin2(char *line, t_pars *e)
{
	ft_strtrimbadass(line);
	if (!ft_strcmp(line, "{"))
		e->scope = OPEN;
	else if (*(line))
	{
		add_err(e, UNKOBJ, line);
		return ;
	}
}

void					p_begin(char *line, t_pars *e)
{
	int		ret;

	if (!ft_strncmp(line, "camera", (ret = 6)))
	{
		e->cur = (t_obj*)ft_memalloc(sizeof(t_camera));
		e->step = PCAMERA;
	}
	else
	{
		add_err(e, UNKOBJ, line);
		return ;
	}
	p_begin2(line + ret, e);
}
