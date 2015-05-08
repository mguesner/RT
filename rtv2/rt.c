/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 08:13:35 by eruffieu          #+#    #+#             */
/*   Updated: 2015/02/27 14:32:18 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init(t_all *c)
{
	if (!(c->dir_vect_cam = (t_vector *)malloc(sizeof(t_vector))) ||
		!(c->rotation = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	if (!(c->first_obj = (t_lst *)malloc(sizeof(t_lst))))
		exit (0);
	if (!(c->first_obj->obj = (t_obj *)malloc(sizeof(t_obj))) ||
	!(c->first_obj->obj->type = (char *)malloc(9 * sizeof(char))) ||
	!(c->first_obj->obj->angle = (t_vector *)malloc(sizeof(t_vector))) ||
	!(c->first_obj->obj->pos = (t_vector *)malloc(sizeof(t_vector))))
		exit (0);
	if (!(c->libx = (t_win *)malloc(sizeof(t_win))))
		exit (0);
	if (!(c->libx->mlx = mlx_init()))
		exit (0);
	c->libx->win = mlx_new_window(c->libx->mlx, 1000, 1000, "rtv1");
	c->libx->img = mlx_new_image(c->libx->mlx, 1000, 1000);
	c->libx->data = mlx_get_data_addr(c->libx->img, &(c->libx->bpp),
		&(c->libx->sizeline), &(c->libx->endian));
}

static int	expose_hook(t_all *c)
{
	raytrace(c);
	return (0);
}

static int	key_hook(int key, t_all *c)
{
	do_key(key, c);
	expose_hook(c);
	return (0);
}

int			main(int argc, char **argv)
{
	t_all	c;

	parse(&c, argv[1]);
	init(&c);
	mlx_expose_hook(c.libx->win, expose_hook, &c);
	mlx_key_hook(c.libx->win, key_hook, &c);
	mlx_loop(c.libx->mlx);
	return (0);
}
