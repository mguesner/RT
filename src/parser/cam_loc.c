/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_loc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 17:35:26 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 17:56:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

static int				fill(char **line, t_pars *e, double *dst)
{
	int			i;
	int			dot;

	ft_strtrimbadass(*line);
	*dst = atof(*line);
	i = 0;
	dot = 0;
	while ((*line)[i] && (ft_isdigit((*line)[i]) || (*line)[i] == '.'))
	{
		dot += (*line)[i] == '.' ? 1 : 0;
		i++;
	}
	if (dot > 1 || !i)
	{
		add_err(e, BADARG, *line);
		return 0;
	}
	*line += i;
	return 1;
}

void					cam_loc(char *line, t_pars *e)
{
	t_point		p;

	if (*line != '<')
	{
		add_err(e, BADARG, line);
		return ;
	}
	line++;
	if (fill(&line, e, &(p.x)) || fill(&line, e, &(p.y)) || fill(&line, e, &(p.z)))
		return ;
	ft_strtrimbadass(line);
	if (*line != '>')
	{
		add_err(e, BADARG, line);
		return ;
	}
}
