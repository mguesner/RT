/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 13:07:19 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/27 17:02:10 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

t_texture texture_init(t_pars *e, char *name)
{
	t_texture	ret;
	char		*file_name;

	ret.exist = 1;
	file_name = ft_strtrijoin("./textures/", name, ".xpm");
	ret.imgv = mlx_xpm_file_to_image(e->mlx,
		file_name,
		&(ret.width), &(ret.height));
	if (ret.imgv == NULL)
	{
		add_err(e, UNKOBJ, name);
		return ret;
	}
	ret.data = mlx_get_data_addr(ret.imgv,
		&(ret.bpp), &(ret.size_line),
		&(ret.endian));
	return (ret);
}

// void    getppx2(t_env *e, t_obj *obj)
// {
//     float    u;
//     float    v;
//     int        col;
//     int        row;
//     int        color;

//     color = 0;
//     u = 0.5 + (atan2((-e->normal.x), (-e->normal.y)) / M_PI);
//     v = 0.5 - asin((e->normal.z)) / M_PI;
//     col = (int)(u * obj->x_text);
//     row = (int)(v * obj->y_text);
//     ft_memcpy(&color,
//         &(obj->data_texture[col * 4 + (row * obj->line_texture)]), 4);
//     e->color[0] = (color >> 16) & 0xFF;
//     e->color[1] = (color >> 8) & 0xFF;
//     e->color[2] = (color & 0xFF);
// }
