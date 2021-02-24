/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:23:29 by choney            #+#    #+#             */
/*   Updated: 2021/02/23 15:21:34 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_f.h"

/*
** проверка на валидность карты
*/

int		ft_verif_map(void)
{
	if (check_min() == 0 || check_breakline() == 0 || check_elem() == 0)
	{
		return (0);
	}
	else
		return (1);
}

int		check_min(void)
{
	if (map[0].col < 1 || map[0].row < 1)
		return (0);
	return (1);
}

int		check_breakline(void)
{
	int i;
	int qty;

	i = 0;
	qty = 0;
	while (map[0].map[i] != '\0')
	{
		if (map[0].map[i] == '\n')
			qty++;
		i++;
	}
	if (qty == map[0].row)
		return (1);
	else
		return (0);
}

int		check_elem(void)
{
	int i;

	i = 0;
	while (map[0].map[i] != '\0')
	{
		if (map[0].map[i] == map[0].full)
			return (0);
		if (!(map[0].map[i] == map[0].empty || map[0].map[i] == map[0].obstacle
			|| map[0].map[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int		check_row_number(char *buff)
{
	char *str;
	int len;
	int i;

	i = 0;
	len = 0;
	while (buff[len] != '\0')
		len++;
	str = (char*) malloc(sizeof(char) * (len - 3));
	while (i < len - 3)
	{
		str[i] = buff[i];
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 && str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
