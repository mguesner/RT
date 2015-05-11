/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 18:07:15 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

//----------------------- parser manuel
t_obj_list_begin *p(void)
{
	t_obj_list_begin *o;

	o = malloc(sizeof(t_obj_list_begin));
	o->begin = malloc(sizeof(t_obj_list));
	o->end = NULL;
	o->size = 1;
	o->begin->obj = malloc(sizeof(t_obj));
	o->begin->obj->type = PLANE;
	o->begin->obj->coord.x = 10.0;
	o->begin->obj->coord.y = 10.0;
	o->begin->obj->coord.z = 10.0;
	o->begin->obj->color.a = 0;
	o->begin->obj->color.r = 100;
	o->begin->obj->color.g = 40;
	o->begin->obj->color.b = 20;
	return (o);
}
//-----------------------

void	usage(void)
{
	ft_putstr("usage: ./RT [scene file]\n");
}

int		main(int argc, char **argv)
{
	t_libx				*mlx;
	t_obj_list_begin	*obj;

	if (argc != 2)
		usage();
	parser(argv[1]);
	obj = p();
	mlx = mlx_struct_init(1000, 1000, "lol");
}
