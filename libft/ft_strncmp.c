/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:47:34 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/14 13:56:59 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
		else if (!*s1)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
