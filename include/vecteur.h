/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:12:58 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/06 16:33:17 by mguesner         ###   ########.fr       */
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

double					scalar(t_vec, t_vec);
double					norme(t_vec);
t_vec					vector(t_vec, t_vec);
t_vec					vec_sum(t_vec, t_vec);
t_vec					vec_coef(t_vec, double);
t_point					translate(t_point, t_vec);
t_vec					make_vec(t_point, t_point);

#endif
