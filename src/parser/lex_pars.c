/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 09:19:21 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/02 15:03:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errno.h>
#include <stdlib.h>

static void				lex_pars2(t_obj_list *lst, t_libx *mlx)
{
	if (lst->obj->type == CAM)
	{
		mlx->cam = (t_camera *)lst->obj;
		ft_memdel((void **)&lst);
	}
	else if (lst->obj->type == LIGHT)
	{
		if (!mlx->spots.size)
			mlx->spots.begin = lst;
		else
			mlx->spots.end->next = lst;
		mlx->spots.size++;
		mlx->spots.end = lst;
		lst->next = NULL;
	}
	else
	{
		if (!mlx->obj.size)
			mlx->obj.begin = lst;
		else
			mlx->obj.end->next = lst;
		mlx->obj.size++;
		mlx->obj.end = lst;
		lst->next = NULL;
	}
}

void					lex_pars(char *file_name, t_libx *mlx)
{
	int			fd;
	t_obj_list	*lst;
	t_obj_list	*next;
	t_pars		e;

	init_pars(&e);
	e.mlx = mlx->mlx;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error(errno);
	lexer(fd, &e);
	if (e.err_list.size && check_pars_err(e))
		exit(-1);
	parser(&e);
	check_pars_err(e);
	if (e.err_list.size)
		exit(-1);
	lst = e.obj_lst.begin;
	next = lst;
	while (next)
	{
		next = next->next;
		lex_pars2(lst, mlx);
		lst = next;
	}
	clean_pars(&e);
}
