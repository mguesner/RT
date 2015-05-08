/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:59:05 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 11:12:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)b;
	i = 0;
	if (!b || !len)
		return (b);
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
