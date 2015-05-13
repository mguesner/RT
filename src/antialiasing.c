/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 11:56:57 by eruffieu          #+#    #+#             */
/*   Updated: 2015/05/13 12:28:33 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <stdlib.h>

void	antialiasing(t_libx *m)
{
	int		i;
	char	*new;

	new = (char *)malloc(((1079) * (m->size_line) + 1919 * (m->bpp / 8)) * sizeof(char));
	i = m->size_line;
	while(i < ((1078) * (m->size_line) + 1919 * (m->bpp / 8)))
	{
		new[i] = ((m->data[i]) + (m->data[i - m->size_line]) + (m->data[i + m->size_line]) + (m->data[i - (m->bpp / 8)]) + (m->data[i + (m->bpp / 8)])) / 5;
		new[i + 1] = ((m->data[i + 1]) + (m->data[i + 1 - m->size_line]) + (m->data[i + 1 + m->size_line]) + (m->data[i + 1 - (m->bpp / 8)]) + (m->data[i + 1 + (m->bpp / 8)])) / 5;
		new[i + 2] = ((m->data[i + 2]) + (m->data[i + 2 - m->size_line]) + (m->data[i + 2 + m->size_line]) + (m->data[i + 2 - (m->bpp / 8)]) + (m->data[i + 2 + (m->bpp / 8)])) / 5;
		i += (m->bpp / 8);
	}
	m->data = new;
}
