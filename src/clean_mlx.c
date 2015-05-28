/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:09:09 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/28 14:21:58 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void						clean_mlx(t_libx *mlx)
{
	mlx->cam = NULL;
	ft_bzero(&(mlx->spots), sizeof(t_obj_list_begin));
	ft_bzero(&(mlx->obj), sizeof(t_obj_list_begin));
}
