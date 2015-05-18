/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 06:18:39 by matthieu          #+#    #+#             */
/*   Updated: 2015/05/16 06:30:10 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICE_H
# define MATRICE_H

void	get_rotate(t_vec axe, double scalaire, double rot[3][3]);
t_point	do_rotate(double rot[3][3], t_point p);

#endif