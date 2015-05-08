/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:37:21 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 13:28:13 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*temp;

	if (!s1 || !s2)
		return (NULL);
	if (!(temp = ft_memalloc(n)))
		return (NULL);
	ft_memcpy(temp, s2, n);
	ft_memcpy(s1, temp, n);
	ft_memdel(&temp);
	return (s1);
}
