/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:50:43 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 18:43:16 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_slot(t_infos *infos, t_tris *tris, int y, int x);
int		ft_final_check(t_infos *infos, t_tris *tris, int y, int x);
int		ft_check_used(t_infos *infos);

int		ft_x(t_infos *infos, int x)
{
	if (x + 1 == infos->sides)
		return (0);
	return (x + 1);
}

int		ft_y(t_infos *infos, int y, int x)
{
	if (x + 1 == infos->sides)
		return (y + 1);
	return (y);
}

int		ft_write_tetri(t_infos *infos, t_tris *tris, int y, int x)
{
	int i;

	i = 0;
	tris->used = 1;
	infos->nb_used++;
	while (i < 4)
	{
		infos->grid[y + tris->coord[i][1]][x + tris->coord[i][0]] = tris->letter;
		i++;
	}
	if (ft_check_used(infos))
		return (1);
	else
	{
		i = 0;
		tris->used = 0;
		infos->nb_used--;
		while (i < 4)
		{
			infos->grid[y + tris->coord[i][1]][x + tris->coord[i][0]] = '.';
			i++;
		}
		return (ft_final_check(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
	}
}

int		ft_check_slot(t_infos *infos, t_tris *tris, int y, int x)
{
	int	i;

	i = 0;
	if (y < (infos->sides - tris->Ymax) && x < (infos->sides - tris->Xmax) && (x - tris->Xmin) >= 0)
	{
		while (i < 4)
		{
			if ((infos->grid[y + tris->coord[i][1]][x + tris->coord[i][0]]) != '.')
				return (ft_final_check(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
			i++;
		}
		if (ft_write_tetri(infos, tris, y, x))
			return (1);
	}
	return (ft_final_check(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
}

int		ft_check_used(t_infos *infos)
{
	t_tris	*tmp;

	tmp = infos->first;
	while (tmp)
	{
		if (tmp->used == 1)
		{
			tmp = tmp->next;
			continue ;
		}
		else
		{
			return (ft_final_check(infos, tmp, 0, 0));
		}
	}
	return (1);
}

int		ft_final_check(t_infos *infos, t_tris *tris, int y, int x)
{
	if (infos->nb_used == infos->nb_tetri)
		return (1);
	if (y + 1 == infos->sides && x + 1 == infos->sides)
		return (0);
	if (infos->grid[y][x] != '.')
		return (ft_final_check(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
	return (ft_check_slot(infos, tris, y, x));
}

int		ft_solve(t_infos *infos)
{
		if (ft_check_used(infos) == 0)
				return (0);
		return (1);
}
