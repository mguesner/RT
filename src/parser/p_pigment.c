/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pigment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 14:41:19 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/12 15:20:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					p_pigment(char *line, t_pars *e, int *off)
{
	int		ret;

	if (!ft_strncmp(line + *off, "}", (ret = 1)))
	{
		e->err = 0;
		e->substep = SSBEGIN;
	}
	else if (e->err)
		;
	else if (!ft_strncmp(line + *off, "{", (ret = 1)))
		e->scope = OPEN;
	else if (e->scope == CLOSE)
		add_err(e, SCOPEMISS, line + *off);
	else if (!ft_strncmp(line + *off, "color rgb", (ret = 9)))
		spot_color(line + ret, e, off);
	else
		add_err(e, UNKPARAM, line + *off);
	*off += ret;
}
