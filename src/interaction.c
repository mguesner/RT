/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsourd-b <bsourd-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 13:44:46 by bsourd-b          #+#    #+#             */
/*   Updated: 2015/05/25 13:44:47 by bsourd-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <matrice.h>

static	void	rot_all_vec(double rot[3][3], t_libx *mlx)
{
	int	pix_x;
	int pix_y;

	pix_y = 0;
	while (pix_y < mlx->height)
	{
		pix_x = 0;
		while (pix_x < mlx->width)
		{
			*(t_point *)(&mlx->pix[pix_x + pix_y * WIDTH]->pos_pix_vec) =
				do_rotate(rot, *(t_point *)(&mlx->pix[pix_x + pix_y * WIDTH]->pos_pix_vec));
			pix_x++;
		}
		pix_y++;
	}
}

void	key_translate_cam(int keycode, t_libx *mlx)
{
	if (keycode == 126)
		mlx->cam->coord.x += 10;
	else if (keycode == 125)
		mlx->cam->coord.x -= 10;
	else if (keycode == 123)
		mlx->cam->coord.y += 10;
	else if (keycode == 124)
		mlx->cam->coord.y -= 10;
}

void	key_rotate_cam(int keycode, t_libx *mlx)
{
	double	angle;
	double	rot[3][3];
	t_vec	x;

	x.x = 1;
	x.y = 0;
	x.z = 0;
	if (keycode == 0)
		angle = 0.984;
	else //if (keycode == 2)
		angle = -0.984;
	get_rotate(x, angle, rot);
	rot_all_vec(rot, mlx);
}