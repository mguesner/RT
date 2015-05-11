/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_look_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:00:13 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 15:06:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

static int				fill(char **line, double *dst, int *off)
{
	int			i;
	int			dot;

	ft_strtrimbadass(*line + *off);
	*dst = atof(*line + *off);
	i = 0;
	dot = 0;
	while ((*line + *off)[i] && (ft_isdigit((*line + *off)[i])
		|| (*line + *off)[i] == '.' || (*line + *off)[i] == '-'))
	{
		dot += (*line + *off)[i] == '.' ? 1 : 0;
		i++;
	}
	if (dot > 1 || !i)
		return (0);
	*off += i;
	ft_strtrimbadass(*line + *off);
	if (*(*line + *off) == ',')
		(*off)++;
	return (1);
}

void					cam_look_at(char *line, t_pars *e, int *off)
{
	t_vec		v;

	ft_strtrimbadass(line + *off);
	if (*line + *off != '<')
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	(*off)++;
	if (!fill(&line, &(v.x), off) || !fill(&line, &(v.y), off)
		|| !fill(&line, &(v.z), off))
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	if (*(line + *off) != '>')
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	(*off)++;
	if (*(line + *off))
		add_err(e, BADARG, line + *off);
	((t_camera*)e->cur)->dir = v;
}
