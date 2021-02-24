/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 00:20:38 by choney            #+#    #+#             */
/*   Updated: 2021/02/23 15:14:51 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_f.h"

int		**ft_memory(int n, int m)
{
	int i;
	int **arr;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * n);
	while (i < n)
	{
		arr[i] = (int*)malloc(sizeof(int) * m);
		i++;
	}
	return (arr);
}

int		ft_atoi(char *str)
{
	int c;
	int s;
	int res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	while (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}
