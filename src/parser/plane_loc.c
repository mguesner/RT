/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_loc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 13:36:32 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 14:10:49 by mguesner         ###   ########.fr       */
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

void					plane_loc(char *line, t_pars *e, int *off)
{
	t_vec		p;
	t_point		p2;

	ft_strtrimbadass(line + *off);
	if (*(line + *off) != '<')
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	(*off)++;
	if (!fill(&line, &(p.x), off) || !fill(&line, &(p.y), off)
		|| !fill(&line, &(p.z), off))
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
	ft_strtrimbadass(line + *off);
	if (*(line + *off) == ',')
		(*off)++;
	ft_strtrimbadass(line + *off);
	if (!fill(&line, &(p2.z), off))
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	if (*(line + *off))
		add_err(e, BADARG, line + *off);
	((t_plane *)e->cur)->norm = p;

}
