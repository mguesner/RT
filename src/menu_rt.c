/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:39:54 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/28 16:39:49 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <dirent.h>

static int	endsWith (char* base, char* str)
{
	int blen = strlen(base);
	int slen = strlen(str);
	return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}

void		menu_rt(t_libx *mlx)
{
	DIR				*root;
	struct dirent	*current;
	int				y;
	int				color;
	t_list			*files;
	t_list			*tmp;

	y = 0;
	root = opendir(mlx->current_dir);
	files = NULL;
	while ((current = readdir(root)))
	{
		if (ft_strcmp(current->d_name, ".") && !(!ft_strcmp(current->d_name, "..") && !ft_strcmp(mlx->current_dir, ".")) && (current->d_type == DT_DIR || endsWith(current->d_name, ".pov")))
		{
			if (!files)
			{
				files = ft_memalloc(sizeof(t_list));
				files->file = ft_strdup(current->d_name);
				tmp = files;
			}
			else
			{
				tmp->next = ft_memalloc(sizeof(t_list));
				tmp->next->file = ft_strdup(current->d_name);
				tmp = tmp->next;
			}
			if (current->d_type == DT_DIR)
			{
				tmp->type = 0;
				color = 0x00ff00;
			}
			else
			{
				tmp->type = 1;
				color = 0xffffff;
			}
			mlx_string_put(mlx->mlx, mlx->window, 0, y, color, current->d_name);
			y += 20;
		}
	}
	mlx->files = files;
	closedir(root);
}
