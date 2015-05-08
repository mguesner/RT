/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrijoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:09:21 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/01 15:17:18 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrijoin(char const *s1, char const *s2, char const *s3)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	ret = ft_strjoin(tmp, s3);
	ft_strdel(&tmp);
	return (ret);
}
