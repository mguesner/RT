/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:28:17 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/11 14:33:53 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	add_obj_lst(t_obj_list_begin *begin, t_obj *elem)
{
	t_obj_list	*node;

	node = ft_memalloc(sizeof(t_obj_list));
	node->obj = elem;
	if (!begin->size)
		begin->begin = node;
	else
		begin->end->next = node;
	begin->end = node;
	begin->size++;
}
