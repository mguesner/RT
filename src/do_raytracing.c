/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:10:08 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 15:39:18 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <matrice.h>

static t_vec	init(t_libx *mlx, t_point ori, t_vec *norm, t_vec *axe)
{
	t_vec		dir;
	double		dist;

	norm->x = 1;
	norm->y = 0;
	norm->z = 0;
	dir = make_vec(mlx->cam->dir, ori);
	dist = norme(dir);
	mlx->cam->pix_bg.x = dist;
	mlx->cam->pix_bg.y = -(WIDTH / 2);
	mlx->cam->pix_bg.z = (HEIGHT / 2);
	mlx->cam->pix_hg.x = dist;
	mlx->cam->pix_hg.y = -(WIDTH / 2);
	mlx->cam->pix_hg.z = -(HEIGHT / 2);
	mlx->cam->pix_hd.x = dist;
	mlx->cam->pix_hd.y = (WIDTH / 2);
	mlx->cam->pix_hd.z = -(HEIGHT / 2);
	dir = normalize(dir);
	*axe = vector(dir, *norm);
	return (dir);
}

void			do_raytracing(t_libx *mlx, t_list *tmp)
{
	char		*name;
	double		rot[3][3];
	t_vec		dir;
	t_vec		axe;
	t_vec		norm;

	name = ft_strtrijoin(mlx->current_dir, "/", tmp->file);
	lex_pars(name, mlx);
	ft_memdel((void **)&name);
	dir = init(mlx, mlx->cam->coord, &norm, &axe);
	if ((mlx->state = 1) && !(!axe.x && !axe.y && !axe.z))
	{
		get_rotate(axe, scalar(dir, norm), rot);
		mlx->cam->pix_bg = do_rotate(rot, mlx->cam->pix_bg);
		mlx->cam->pix_bg = translate(mlx->cam->pix_bg
			, *(t_vec *)(&mlx->cam->coord));
		mlx->cam->pix_hg = do_rotate(rot, mlx->cam->pix_hg);
		mlx->cam->pix_hg = translate(mlx->cam->pix_hg
			, *(t_vec *)(&mlx->cam->coord));
		mlx->cam->pix_hd = do_rotate(rot, mlx->cam->pix_hd);
		mlx->cam->pix_hd = translate(mlx->cam->pix_hd
			, *(t_vec *)(&mlx->cam->coord));
	}
	mlx->superint = 0;
	mlx->pix = precalc_vec_cam(mlx->cam);
}
