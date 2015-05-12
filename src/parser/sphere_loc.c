/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_loc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:19:19 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 14:21:46 by mguesner         ###   ########.fr       */
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

void					sphere_loc(char *line, t_pars *e, int *off)
{
	t_point		p;

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
	if (!fill(&line, &((t_sphere *)e->cur)->radius, off))
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	if (*(line + *off))
		add_err(e, BADARG, line + *off);
	((t_sphere *)e->cur)->coord = p;
}
