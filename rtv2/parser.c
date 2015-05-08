/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 08:13:41 by eruffieu          #+#    #+#             */
/*   Updated: 2015/02/26 12:54:11 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char		*read_buffer(char *argv)
{
	int		fd;
	char	*buffer;

	if (!(buffer = (char *)malloc(10000 * sizeof(char))))
		exit(0);
	fd = open(argv, O_RDONLY);
	read(fd, buffer, 10000);
	return (buffer);
}

char			*find_num(char *buffer, int *pos)
{
	int		i;
	char	*num;

	i = 0;
	num = (char *)malloc(11 * sizeof(char));
	while (buffer[*pos] != ':')
		(*pos)++;
	(*pos)++;
	while (buffer[*pos] != '\n')
	{
		num[i] = buffer[*pos];
		i++;
		(*pos)++;
	}
	num[i] = '\0';
	return (num);
}

static	t_lst	*new_list(char *buffer, int *pos)
{
	t_lst	*new;
	int		i;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!(new->obj = (t_obj *)malloc(sizeof(t_obj))) ||
	!(new->obj->type = (char *)malloc(9 * sizeof(char))) ||
	!(new->obj->angle = (t_vector *)malloc(sizeof(t_vector))) ||
	!(new->obj->pos = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	i = 0;
	while (buffer[*pos] != ':')
	{
		new->obj->type[i] = buffer[*pos];
		(*pos)++;
		i++;
	}
	new->obj->type[i] = '\0';
	(*pos)++;
	new->obj->pos->x = atof(find_num(buffer, pos));
	new->obj->pos->y = atof(find_num(buffer, pos));
	new->obj->pos->z = atof(find_num(buffer, pos));
	new->obj->angle->x = atof(find_num(buffer, pos));
	new->obj->angle->y = atof(find_num(buffer, pos));
	new->obj->angle->z = atof(find_num(buffer, pos));
	new->obj->other = atof(find_num(buffer, pos));
	new->obj->blue_color = ft_atoi(find_num(buffer, pos));
	new->obj->green_color = ft_atoi(find_num(buffer, pos));
	new->obj->red_color = ft_atoi(find_num(buffer, pos));
	new->next = NULL;
	(*pos) += 4;
	return (new);
}

static	t_lst	*new_spot(char *buffer, int *pos)
{
	t_lst	*new;
	int		i;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!(new->obj = (t_obj *)malloc(sizeof(t_obj))) ||
	!(new->obj->type = (char *)malloc(9 * sizeof(char))) ||
	!(new->obj->angle = (t_vector *)malloc(sizeof(t_vector))) ||
	!(new->obj->pos = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	i = 0;
	while (buffer[*pos] != ':')
	{
		new->obj->type[i] = buffer[*pos];
		(*pos)++;
		i++;
	}
	new->obj->type[i] = '\0';
	(*pos)++;
	new->obj->pos->x = atof(find_num(buffer, pos));
	new->obj->pos->y = atof(find_num(buffer, pos));
	new->obj->pos->z = atof(find_num(buffer, pos));
	new->obj->other = atof(find_num(buffer, pos));
	new->next = NULL;
	(*pos) += 4;
	return (new);
}

void			parse(t_all *c, char *argv)
{
	char	*buffer;
	int		pos;
	t_lst	*temp;

	pos = 0;
	buffer = read_buffer(argv);
	c->camera = fill_camera(buffer, &pos);
	pos += 4;
	c->list = new_list(buffer, &pos);
	temp = c->list;
	while (buffer[pos] != '@')
	{
		temp->next = new_list(buffer, &pos);
		temp = temp->next;
	}
	pos += 3;
	c->list_spot = new_spot(buffer, &pos);
	temp = c->list_spot;
	while (buffer[pos] != '*')
	{
		temp->next = new_spot(buffer, &pos);
		temp = temp->next;
	}
}
