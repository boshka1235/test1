/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:20:36 by choney            #+#    #+#             */
/*   Updated: 2021/02/23 15:43:40 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_f.h"

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1 && read_file(argc, argv[0]) == 0)
	{
		write(2, "map error\n", 10);
		return (1);
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			if (read_file(argc, argv[i]) == 0)
			{
				write(2, "map error\n", 10);
				break ;
			}
			i++;
		}
	}
	return (0);
}
