/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:21:01 by choney            #+#    #+#             */
/*   Updated: 2021/02/23 15:24:11 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_f.h"

/*
** чтение файла
*/

int		read_file(int argc, char *map_file)
{
	int res;
	int **matrix;

	if (argc == 1)
	{
		if (get_map_stdin() == 0)
			return (0);
		if (ft_verif_map() == 0)
		return (0);
	matrix = map_to_int();
	res = largest_square(map[0].row, map[0].col, matrix);
	map[0].pos_x = map[0].row;
	map[0].pos_y = map[0].col;
	search_square(res, &map[0].pos_x, &map[0].pos_y, matrix);
	inverse_array(res, map[0].row, map[0].col - 1, matrix);
	return (1);
	}
	else
	{
		if (get_map(map_file) == 0)
			return (0);
	if (ft_verif_map() == 0)
		return (0);
	matrix = map_to_int();
	res = largest_square(map[0].row, map[0].col, matrix);
	map[0].pos_x = map[0].row;
	map[0].pos_y = map[0].col;
	search_square(res, &map[0].pos_x, &map[0].pos_y, matrix);
	inverse_array(res, map[0].row, map[0].col, matrix);
	return (1);
	}
}

int		get_map(char *map_file)
{
	int		fd;
	char	first_l[64];
	int		i;

	map[0].map = (char*)malloc(sizeof(char) * ft_size_map(map_file));
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &first_l[i], 1) && first_l[i] != '\n')
		i++;
	first_l[i] = '\0';
	i = 0;
	while (read(fd, &map[0].map[i], 1) && map[0].map[i] != '\0')
		i++;
	map[0].map[i] = '\0';
	close(fd);
	if (get_info_map(first_l) == 0)
		return (0);
	map[0].col = (((ft_size_map(map_file) - 1) / map[0].row) - 1);
	return (1);
}

int	get_map_stdin(void)
{
	int		i;
	int		j;
	char	first_l[64];

	map[0].map = (char*)malloc(sizeof(char) * 4096);
	i = 0;
	while (read(0, &first_l[i], 1) && first_l[i] != '\n')
		i++;
	first_l[i] = '\0';
	if (get_info_map(first_l) == 0)
		return (0);
	j = 0;
	while (read(0, &map[0].map[j], 1) && map[0].map[j] != '\0')
		j++;
	map[0].map[j] = '\0';
	map[0].col = j / map[0].row;
	return (1);
}

int	get_info_map(char *buff)
{
	int i;
	int l;

	i = 0;
	l = 0;
	if (!(check_row_number(buff) == 0))
	{
		while (buff[i] != '\0')
		{
			if (buff[i] >= '0' && buff[i] <= '9')
			{
				map[0].nb_line[l] = buff[i];
				l++;
			}
			else
			{
				map[0].nb_line[l] = '\0';
				map[0].empty = buff[i++];
				map[0].obstacle = buff[i++];
				map[0].full = buff[i];
			}
			i++;
		}
		map[0].row = ft_atoi(map[0].nb_line);
		return (1);
	}
	else
		return (0);
}

int		**map_to_int(void)
{
	int **matrix;
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	matrix = ft_memory(map[0].row, map[0].col);
	while (map[0].map[i] != '\0')
	{
		x = 0;
		while (map[0].map[i] != '\n')
		{
			if (map[0].map[i] == map[0].empty)
				matrix[y][x] = 1;
			else if (map[0].map[i] == map[0].obstacle)
				matrix[y][x] = 0;
			i++;
			x++;
		}
		y++;
		i++;
	}
	return (matrix);
}
