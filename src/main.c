/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 10:28:41 by mguesner          #+#    #+#             */
/*   Updated: 2015/05/08 11:21:57 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	usage(void)
{
	ft_putstr("usage: ./RT [scene file]\n");
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	parser(argv[1]);
}
