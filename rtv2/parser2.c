/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 09:05:35 by eruffieu          #+#    #+#             */
/*   Updated: 2015/02/25 14:07:29 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	move_to_next(char *buffer, int *pos)
{
	while (buffer[*pos] != ':')
		(*pos)++;
	(*pos)++;
}

static void	malloc_cam(t_camera *new)
{
	if (!(new->pos = (t_vector *)malloc(sizeof(t_vector))) ||
	!(new->pos_hg = (t_vector *)malloc(sizeof(t_vector))) ||
	!(new->pos_bg = (t_vector *)malloc(sizeof(t_vector))) ||
	!(new->pos_hd = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
}

t_camera	*fill_camera(char *buffer, int *pos)
{
	t_camera	*new;

	if (!(new = (t_camera *)malloc(sizeof(t_camera))))
		exit (0);
	malloc_cam(new);
	while (buffer[*pos] != '{')
		(*pos)++;
	move_to_next(buffer, pos);
	new->pos->x = atof(find_num(buffer, pos));
	new->pos->y = atof(find_num(buffer, pos));
	new->pos->z = atof(find_num(buffer, pos));
	move_to_next(buffer, pos);
	new->pos_hg->x = atof(find_num(buffer, pos));
	new->pos_hg->y = atof(find_num(buffer, pos));
	new->pos_hg->z = atof(find_num(buffer, pos));
	move_to_next(buffer, pos);
	new->pos_hd->x = atof(find_num(buffer, pos));
	new->pos_hd->y = atof(find_num(buffer, pos));
	new->pos_hd->z = atof(find_num(buffer, pos));
	move_to_next(buffer, pos);
	new->pos_bg->x = atof(find_num(buffer, pos));
	new->pos_bg->y = atof(find_num(buffer, pos));
	new->pos_bg->z = atof(find_num(buffer, pos));
	return (new);
}
