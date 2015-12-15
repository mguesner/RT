/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:12:58 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/01 13:57:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTEUR_H
# define VECTEUR_H

# include <math.h>

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

double					scalar(t_vec a, t_vec b);
double					norme(t_vec v);
t_vec					normalize(t_vec v);
t_vec					vector(t_vec a, t_vec b);
t_vec					vec_sum(t_vec a, t_vec b);
t_vec					vec_coef(t_vec v, double r);
t_point					translate(t_point p, t_vec v);
t_vec					make_vec(t_point a, t_point b);
void					pointcpy(t_point *dst, t_point src);

#endif
