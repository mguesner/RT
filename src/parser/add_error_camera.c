/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_error_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 13:31:36 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/13 13:32:09 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void					add_error_camera(t_pars *e, t_lex **node)
{
	add_err(e, UNKOBJ, (*node)->value);
}
