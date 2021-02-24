/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:54:28 by choney            #+#    #+#             */
/*   Updated: 2021/02/23 15:57:27 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_F_H
# define ALL_F_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

struct	s_first_line
{
	char	nb_line[10];
	char	empty;
	char	obstacle;
	char	full;
	int		row;
	int		col;
	char	*map;
	int		pos_x;
	int		pos_y;
};

struct s_first_line map[1];

/*
** base
*/

int		**ft_memory(int n, int m);
int		ft_atoi(char *str);

/*
** file_read
*/

int		read_file(int argc, char *map_file);
int		get_map(char *map_file);
int	get_map_stdin(void);
int	get_info_map(char *buff);
int		**map_to_int(void);

/*
** brain_square
*/

int		largest_square(int nb_x, int nb_y, int **m);
int		min_v(char a, char b, char c);
void	search_square(int res, int *nb_x, int *nb_y, int **matrix);
void	inverse_array(int res, int row, int col, int **matrix);
void	inverse_array_aux(int res, int col, int **matrix, int i);

/*
**  check1
*/

int		ft_verif_map(void);
int		check_min(void);
int		check_breakline(void);
int		check_elem(void);
int		check_row_number(char *str);

/*
**  map_size
*/

int		ft_file_size(char *map_file);
int		ft_size_firstline(char *map_file);
int		ft_size_map(char *map_file);
int		ft_size_stdin(void);
int		ft_size_stdin_firstline(void);

/*
**  check2
*/

int		check_row_size(void);
int		check_row_size(void);
int		check_row_qty(void);

#endif