/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 14:15:53 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 15:03:45 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

static void				next(t_pars *e, char *value, int *i)
{
	int		dot;
	int		sign;

	dot = 0;
	sign = 0;
	if (value[*i] == '-')
		(*i)++;
	while (ft_isdigit(value[*i]) || value[*i] == '.')
	{
		if (value[*i] == '.')
			dot++;
		(*i)++;
	}
	if (!*i || dot > 1)
		add_err(e, BADARG, value);
	while (value[*i] == ' ' || value[*i] == '\t')
		(*i)++;
	if (value[*i] == ',')
		(*i)++;
	while (value[*i] == ' ' || value[*i] == '\t')
		(*i)++;
}

int						fill_vector(t_pars *e, char *value, t_vec *vec)
{
	int		i;

	i = 1;
	vec->x = atof(value + i);
	next(e, value, &i);
	vec->y = atof(value + i);
	next(e, value, &i);
	vec->z = atof(value + i);
	next(e, value, &i);
	while (value[i] == ' ' || value[i] == '\t')
		i++;
	if (value[i] != '>')
	{
		add_err(e, BADARG, value);
		return (0);
	}
	return (1);
}
