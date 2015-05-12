/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 10:03:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/12 14:17:19 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <vecteur.h>

int		is_in_light(t_point *p, t_obj_list *list)
{
	t_vec		vec;
	t_obj_list	*tmp;
	t_obj_list	*tmp2;

	tmp = list;
	while (tmp)
	{
		if (tmp->obj->type == LIGHT)
		{
			vec = make_vec(tmp->obj->coord, *p);
			tmp2 = list;
			while (tmp2)
			{
				if (touch(tmp2->obj, &vec, p) > 0)
					return (0);
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
