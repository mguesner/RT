/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 13:07:19 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/19 14:04:57 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>

void textures_init(t_libx *mlx)
{
	mlx->texture.imgv = mlx_xpm_file_to_image(mlx->mlx,
		"./textures/texture_jupiter.xpm",
		&(mlx->texture.width), &(mlx->texture.height));
	if (mlx->texture.imgv == NULL)
	{
		ft_putendl("error: texture file not found");
		exit(0);
	}
	mlx->texture.data = mlx_get_data_addr(mlx->texture.imgv,
		&(mlx->texture.bpp), &(mlx->texture.size_line),
		&(mlx->texture.endian));
}
