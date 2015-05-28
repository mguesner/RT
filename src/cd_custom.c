/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_custom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:17:45 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/28 13:48:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void						cd_custom(t_libx *mlx, char *file)
{
	int		size;
	int		i;

	size = ft_strlen(mlx->current_dir);
	if (!ft_strcmp(file, "."))
		return ;
	else if (!ft_strcmp(file, ".."))
	{
		i = size - 1;
		while (i > 0 && mlx->current_dir[i] != '/')
			i--;
		if (i)
			mlx->current_dir[i] = 0;
	}
	else if (size + ft_strlen(file) + 1 < PATH_MAX)
	{
		ft_strcat(mlx->current_dir, "/");
		ft_strcat(mlx->current_dir, file);
	}
}
