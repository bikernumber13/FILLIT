/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 14:55:28 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/30 11:20:34 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_write_tetri(t_infos *infos, t_tris *tris, int y, int x)
{
	int		i;

	i = 0;
	tris->used = 1;
	infos->nb_used = infos->nb_used + 1;
	while (i < 4)
	{
		infos->grid[y + tris->coord[i][1]][x + tris->coord[i][0]] = tris->let;
		i++;
	}
	if (ft_check_used(infos) == 1)
		return (1);
	else
	{
		i = 0;
		tris->used = 0;
		infos->nb_used = infos->nb_used - 1;
		while (i < 4)
		{
			infos->grid[y + tris->coord[i][1]][x + tris->coord[i][0]] = '.';
			i++;
		}
		return (ft_final_c(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
	}
}

int		ft_check_slot(t_infos *infos, t_tris *tris, int y, int x)
{
	int	i;

	i = 0;
	if ((y < (infos->sides - tris->ymax)) && (x < (infos->sides - tris->xmax))
		&& ((x - tris->xmin) >= 0))
	{
		while (i < 4)
		{
			if (infos->grid[y + tris->coord[i][1]][x + tris->coord[i][0]]
				!= '.')
			{
				return (ft_final_c(infos, tris, ft_y(infos, y, x),
						ft_x(infos, x)));
			}
			i++;
		}
		return (ft_write_tetri(infos, tris, y, x));
	}
	else
		return (ft_final_c(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
}

int		ft_check_used(t_infos *infos)
{
	t_tris	*tmp;

	tmp = infos->first;
	while (tmp)
	{
		if (tmp->used == 1)
			tmp = tmp->next;
		else
			return (ft_final_c(infos, tmp, 0, 0));
	}
	return (1);
}

int		ft_final_c(t_infos *infos, t_tris *tris, int y, int x)
{
	if (infos->nb_used == infos->nb_tetri)
		return (1);
	else if (y + 1 == infos->sides && x + 1 == infos->sides)
		return (0);
	else if (infos->grid[y][x] != '.')
		return (ft_final_c(infos, tris, ft_y(infos, y, x), ft_x(infos, x)));
	else
		return (ft_check_slot(infos, tris, y, x));
}
