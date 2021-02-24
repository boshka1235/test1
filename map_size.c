/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 04:32:03 by choney            #+#    #+#             */
/*   Updated: 2021/02/23 14:57:30 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_f.h"

int		ft_file_size(char *map_file)
{
	int		fd;
	char	buff;
	int		size;

	fd = open(map_file, O_RDONLY);
	size = 0;
	if (fd >= 0)
	{
		while (read(fd, &buff, 1))
			size++;
		close(fd);
		return (size);
	}
	else
	{
		return (0);
	}
}

int		ft_size_firstline(char *map_file)
{
	int		fd;
	char	buff;
	int		size;

	fd = open(map_file, O_RDONLY);
	size = 0;
	if (fd >= 0)
	{
		while (read(fd, &buff, 1) && buff != '\n')
			size++;
		close(fd);
		return (size);
	}
	else
	{
		return (0);
	}
}

int		ft_size_map(char *map_file)
{
	int size;

	size = 0;
	size = ft_file_size(map_file) - ft_size_firstline(map_file);
	return (size);
}

int		ft_size_stdin(void)
{
	char	buff;
	int		size;

	size = 0;
	while (read(0, &buff, 1))
		size++;
	return (size);
}

int		ft_size_stdin_firstline(void)
{
	char	buff;
	int		size;

	size = 0;
	read(0, &buff, 1);
	while (read(0, &buff, 1) && buff != '\n')
	{
		size++;
	}
	return (size);
}
