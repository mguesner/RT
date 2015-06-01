/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 16:39:54 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 17:13:25 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <dirent.h>
#include <errno.h>

typedef struct dirent	t_dirent;

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
	mlx->files = NULL;
}

static void	add_file(t_list **files, t_list **tmp, t_dirent *current)
{
	if (!(*files))
	{
		(*files) = ft_memalloc(sizeof(t_list));
		(*files)->file = ft_strdup(current->d_name);
		(*files)->type = current->d_type == DT_DIR ? 0 : 1;
		*tmp = *files;
	}
	else
	{
		(*tmp)->next = ft_memalloc(sizeof(t_list));
		(*tmp)->next->file = ft_strdup(current->d_name);
		(*tmp)->next->type = current->d_type == DT_DIR ? 0 : 1;
		*tmp = (*tmp)->next;
	}
}

void		menu_rt(t_libx *mlx)
{
	DIR				*root;
	t_dirent		*current;
	int				y;
	t_list			*tmp;

	if (!(root = opendir(mlx->current_dir)))
		error(errno);
	if (mlx->files)
		clean_files(mlx);
	y = 0;
	tmp = NULL;
	while ((current = readdir(root)))
	{
		if (ft_strcmp(current->d_name, ".")
			&& !(!ft_strcmp(current->d_name, "..")
			&& !ft_strcmp(mlx->current_dir, ".")) && (current->d_type == DT_DIR
			|| ends_with(current->d_name, ".pov")))
		{
			add_file(&mlx->files, &tmp, current);
			mlx_string_put(mlx->mlx, mlx->window, 0, y, (current->d_type
		== DT_DIR && !(tmp->type = 0)) ? 0x00ff00 : 0xffffff, current->d_name);
			y += 20;
		}
	}
	closedir(root);
}
