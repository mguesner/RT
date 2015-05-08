/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:13:06 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 10:47:17 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <vecteur.h>
# include <color.h>
# include <libft.h>
# include <parser.h>

typedef enum				e_obj_type
{
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	NBOBJTYPE
}							t_obj_type;

typedef struct				s_obj
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
}							t_obj;

typedef struct				s_plane
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	t_vec					norm;
}							t_plane;

typedef struct				s_sphere
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	int						radius;
}							t_sphere;

typedef struct				s_cylinder
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	t_vec					dir;
	int						radius;
}							t_cylinder;

typedef struct				s_cone
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	int						angle;
	t_vec					dir;
}							t_cone;

void						error(int errno);

#endif
