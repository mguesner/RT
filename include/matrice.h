/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:18:39 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/25 16:58:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

void	get_rotate(t_vec axe, double scalaire, double rot[3][3]);
t_point	do_rotate(double rot[3][3], t_point p);
t_vec	do_rotate_vec(double rot[3][3], t_vec p);
void	inverse_rot(double dst[3][3], double src[3][3]);

#endif
