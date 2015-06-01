/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:39:54 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 11:32:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <dirent.h>
#include <errno.h>

static int	ends_with(char *base, char *str)
{
	int blen;
	int slen;

	blen = strlen(base);
	slen = strlen(str);
	return ((blen >= slen) && (0 == strcmp(base + blen - slen, str)));
}

static void	clean_files(t_libx *mlx)
{
	t_list			*cur;
	t_list			*next;

	cur = mlx->files;
	while (cur)
	{
		next = cur->next;
		ft_memdel((void **)&(cur->file));
		ft_memdel((void **)&(cur));
		cur = next;
	}
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
	if (!(root = opendir(mlx->current_dir)))
		error(errno);
	files = NULL;
	while ((current = readdir(root)))
	{
		if (ft_strcmp(current->d_name, ".") && !(!ft_strcmp(current->d_name, "..")
			&& !ft_strcmp(mlx->current_dir, ".")) && (current->d_type == DT_DIR
			|| ends_with(current->d_name, ".pov")))
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
			if (current->d_type == DT_DIR && !(tmp->type = 0))
				color = 0x00ff00;
			else if ((tmp->type = 1))
				color = 0xffffff;
			mlx_string_put(mlx->mlx, mlx->window, 0, y, color, current->d_name);
			y += 20;
		}
	}
	if (mlx->files)
		clean_files(mlx);
	mlx->files = files;
	closedir(root);
}
