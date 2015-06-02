/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pars_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 14:56:47 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 15:03:04 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

int						check_pars_err(t_pars e)
{
	t_err	*err;

	err = e.err_list.begin;
	while (err)
	{
		ft_printf("./RT : %s: %s: line %d\n", e.err_msg[err->err_type]
			, err->where, err->line);
		err = err->next;
	}
	return (1);
}
