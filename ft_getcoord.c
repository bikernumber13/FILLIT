/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 20:00:43 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 18:40:03 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_yxmax(t_tris	*tris)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tris->coord[i][1] > tris->coord[i + 1][1])
			tris->Ymax = tris->coord[i][1];
		else
			tris->Ymax = tris->coord[i + 1][1];

		if (tris->coord[i][0] > tris->coord[i + 1][0])
			tris->Xmax = tris->coord[i][0];
		else
			tris->Xmax = tris->coord[i + 1][0];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (tris->coord[i][0] < tris->coord[i + 1][0])
		{
			tris->Xmin = tris->coord[i][0];
			break ;
		}
		else
			tris->Xmin = tris->coord[i + 1][0];
		i++;
	}
}


void	ft_stock_yx(char *tetri, t_tris *tris, int y, int x)
{
	int		i;
	int		temp[2];
	int		hash;

	i = 0;
	hash = 0;
	while (y++ < 4)
	{
		x = -1;
		while (x++ < 4)
		{
			if (tetri[i] == '#')
			{
				temp[1] = hash > 0 ? temp[1] : y;
				temp[0] = hash > 0 ? temp[0] : x;
				tris->coord[hash][1] = y - temp[1];
				tris->coord[hash][0] = x - temp[0];
				hash++;
			}
			i++;
		}
	}
	ft_yxmax(tris);
}

t_tris		*ft_create_elem(t_infos *infos, char *tetri)
{
	t_tris		*tris;

	if (!(tris = malloc(sizeof(t_tris))))
		return (NULL);
	ft_stock_yx(tetri, tris, -1, -1);
	tris->next = NULL;
	tris->used = 0;
	tris->letter = 'A' + infos->nb_tetri;
	infos->nb_tetri++;
	return (tris);
}

void		ft_tris_push_back(t_infos *infos, char *tetri)
{
	t_tris		*tris;

	tris = infos->first;
	if (infos->first)
	{
		while (tris->next)
			tris = tris->next;
		tris->next = ft_create_elem(infos, tetri);
	}
	else
		infos->first = ft_create_elem(infos, tetri);
}
