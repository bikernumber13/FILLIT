/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:33:05 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 15:56:58 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_sizegrid(t_infos *infos)
{
	while ((infos->nb_tetri * 4) > (infos->sides * infos->sides))
		infos->sides++;
}

void	ft_creategrid(t_infos *infos)
{
	int y;
	int x;

	y = 0;
	if (infos->grid)
		free(infos->grid);
	if (!(infos->grid = (char **)malloc(sizeof(char*) * (infos->sides + 1))))
		return ;
	while (y < infos->sides)
	{
		if (!(infos->grid[y] = (char *)malloc(sizeof(char) * (infos->sides + 1))))
			return ;
		x = 0;
		while (x < infos->sides)
			infos->grid[y][x++] = '.';
		infos->grid[y][x] = '\0';
		y++;
	}
	infos->grid[y] = NULL;
	infos->x = 0;
	infos->y = 0;
	infos->link = infos->first;
}

void	ft_grid(t_infos *infos)
{
	ft_sizegrid(infos);
	ft_creategrid(infos);
	while (!ft_solve(infos))
	{
		infos->sides++;
		ft_creategrid(infos);
	}
}
