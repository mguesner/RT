/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 13:07:19 by aleung-c          #+#    #+#             */
/*   Updated: 2015/05/19 15:13:12 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <stdlib.h>

t_texture texture_init(t_pars *e, char *name)
{
	t_texture	ret;
	char		*file_name;

	file_name = ft_strtrijoin("./textures/", name, ".xpm");
	ret.imgv = mlx_xpm_file_to_image(e->mlx,
		file_name,
		&(ret.width), &(ret.height));
	if (ret.imgv == NULL)
		add_err(e, UNKOBJ, name);
	ret.data = mlx_get_data_addr(ret.imgv,
		&(ret.bpp), &(ret.size_line),
		&(ret.endian));
	return (ret);
}
