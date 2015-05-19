/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:18:39 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/19 13:03:12 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

void	get_rotate(t_vec axe, double scalaire, double rot[3][3]);
t_point	do_rotate(double rot[3][3], t_point p);
t_vec	do_rotate_vec(double rot[3][3], t_vec p);

#endif
