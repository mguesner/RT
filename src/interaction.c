/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 13:44:46 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/06/03 15:35:01 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <matrice.h>

static void	rot_all_vec(double rot[3][3], t_libx *mlx)
{
	int	i;

	i = 0;
	while (i < TOTAL_PIX)
	{
		*(t_point *)(&mlx->pix[i]->pos_pix_vec) =
			do_rotate(rot, *(t_point *)(&mlx->pix[i]->pos_pix_vec));
		i++;
	}
}

static void	rot_cam_axe(t_vec axe, int keycode, t_libx *mlx)
{
	double	angle;
	double	rot[3][3];

	if (keycode == 12 || keycode == 13 || keycode == 14)
		angle = 10.0;
	else
		angle = -10.0;
	get_rotate_angle(axe, angle, rot);
	rot_all_vec(rot, mlx);
}

void		key_rotate_cam(int keycode, t_libx *mlx)
{
	t_vec	axe;

	if (keycode == 12 || keycode == 0)
	{
		axe.x = 1;
		axe.y = 0;
		axe.z = 0;
	}
	else if (keycode == 13 || keycode == 1)
	{
		axe.x = 0;
		axe.y = 1;
		axe.z = 0;
	}
	else
	{
		axe.x = 0;
		axe.y = 0;
		axe.z = 1;
	}
	rot_cam_axe(axe, keycode, mlx);
}

void		key_translate_cam(int keycode, t_libx *mlx)
{
	if (keycode == 126)
		mlx->cam->coord.z += 20;
	else if (keycode == 125)
		mlx->cam->coord.z -= 20;
	else if (keycode == 123)
		mlx->cam->coord.y += 20;
	else if (keycode == 124)
		mlx->cam->coord.y -= 20;
	else if (keycode == 78)
		mlx->cam->coord.x += 20;
	else if (keycode == 69)
		mlx->cam->coord.x -= 20;
	else if (keycode == 6)
		mlx->antialia = (mlx->antialia == -1) ? 1 : -1;
	else if (keycode == 7)
		mlx->cshade = (mlx->cshade == -1) ? 1 : -1;
	else if (keycode == 8)
		mlx->mblur = (mlx->mblur == -1) ? 1 : -1;
	else if (keycode == 9)
		mlx->sepia = (mlx->sepia == -1) ? 1 : -1;
	else if (keycode == 11)
		mlx->screen = (mlx->screen == -1) ? 1 : -1;
}
