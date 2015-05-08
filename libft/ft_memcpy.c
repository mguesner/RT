/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:32:52 by mguesner          #+#    #+#             */
/*   Updated: 2013/12/01 10:15:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*temp1;
	char		*temp2;

	if (!s1 || !s2 || !n)
		return (s1);
	temp1 = (char *)s1;
	temp2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (s1);
}
