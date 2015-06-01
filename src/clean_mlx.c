/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:09:09 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 11:23:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void						clean_mlx2(t_libx *mlx)
{
	int			i;

	i = 0;
	while (i < TOTAL_PIX)
	{
		ft_memdel((void **)&(mlx->pix[i]->color));
		ft_memdel((void **)&(mlx->pix[i]->color_specular));
		ft_memdel((void **)&mlx->pix[i]);
		i++;
	}
	ft_memdel((void **)&mlx->pix);
	ft_memdel((void **)&mlx->cam);
	ft_bzero(&(mlx->spots), sizeof(t_obj_list_begin));
	ft_bzero(&(mlx->obj), sizeof(t_obj_list_begin));
}

void						clean_mlx(t_libx *mlx)
{
	t_obj_list	*tmp;
	t_obj_list	*next;

	tmp = mlx->spots.begin;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void **)&tmp->obj);
		ft_memdel((void **)&tmp);
		tmp = next;
	}
	tmp = mlx->obj.begin;
	while (tmp)
	{
		next = tmp->next;
		ft_memdel((void **)&tmp->obj);
		ft_memdel((void **)&tmp);
		tmp = next;
	}
	clean_mlx2(mlx);
}
