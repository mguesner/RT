/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:11:02 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/20 20:12:45 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	t1;
	unsigned char	t2;

	if (!s1 || !s2 || !n)
		return (0);
	while (n > 0)
	{
		t1 = *(unsigned char *)s1;
		t2 = *(unsigned char *)s2;
		if (t1 != t2)
			return (t1 - t2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
