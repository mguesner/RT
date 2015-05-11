/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_begin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 12:50:24 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 15:06:25 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_begin(char *line, t_pars *e, int *off)
{
	int ret;

	ret = 0;
	if (e->err)
		;
	else if (!ft_strncmp(line + *off, "camera", (ret = 6)))
	{
		e->cur = (t_obj*)ft_memalloc(sizeof(t_camera));
		e->cur->type = CAM;
		e->step = PCAMERA;
	}
	else if (!ft_strncmp(line + *off, "light_source", (ret = 12)))
	{
		e->cur = (t_obj*)ft_memalloc(sizeof(t_light));
		e->cur->type = LIGHT;
		e->step = PSPOT;
	}
	else
		add_err(e, UNKOBJ, line);
	*off += ret;
}
