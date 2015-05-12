/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:14:23 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 15:20:40 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

static int				fill(char **line, int *dst, int *off)
{
	int			i;
	int			dot;

	ft_strtrimbadass(*line + *off);
	*dst = atof(*line + *off) * 255;
	i = 0;
	dot = 0;
	while ((*line + *off)[i] && (ft_isdigit((*line + *off)[i]) || (*line + *off)[i] == '.'))
	{
		dot += (*line + *off)[i] == '.' ? 1 : 0;
		i++;
	}
	if (!i)
		return (0);
	*off += i;
	ft_strtrimbadass(*line + *off);
	if (*(*line + *off) == ',')
		(*off)++;
	return (1);
}

static int				get_alpha(char *line, int *dst, int *off)
{
	int			i;
	int			dot;

	ft_strtrimbadass(line + *off);
	if (*(line + *off) != '*')
	{
		*dst = 255;
		return (1);
	}
	(*off)++;
	ft_strtrimbadass(line + *off);
	*dst = atof(line + *off) * 255;
	i = 0;
	dot = 0;
	while ((line + *off)[i] && (ft_isdigit((line + *off)[i])
		|| (line + *off)[i] == '.'))
	{
		dot += (line + *off)[i] == '.' ? 1 : 0;
		i++;
	}
	if (dot > 1 || !i)
		return (0);
	*off += i;
	return (1);
}

void					spot_color(char *line, t_pars *e, int *off)
{
	t_color		p;

	ft_strtrimbadass(line + *off);
	if (*(line + *off) != '<')
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	(*off)++;
	if (!fill(&line, &(p.r), off) || !fill(&line, &(p.g), off)
		|| !fill(&line, &(p.b), off))
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
	if (!get_alpha(line, &p.a, off))
	{
		add_err(e, BADARG, line + *off);
		return ;
	}
	// if (*(line + *off))
	// 	add_err(e, BADARG, line + *off);
	// else
	e->cur->color = p;
}
