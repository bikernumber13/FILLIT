/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:48:32 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 13:40:02 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_countlines(char *tetri)
{
	if (tetri[4] != '\n')
		return (0);
	if (tetri[9] != '\n')
		return (0);
	if (tetri[14] != '\n')
		return (0);
	if (tetri[19] != '\n')
		return (0);
	return (1);
}

int			ft_checkpairs(char *tetri, int i, int check)
{
	while (tetri[i++])
		if (tetri[i] == '#')
		{
			if (tetri[i + 1] == '#')
				check = 1;
			if (i > 0)
				if (tetri[i - 1] == '#')
					check = 1;
			if (i < 15)
				if (tetri[i + 5] == '#')
					check = 1;
			if (i > 5)
				if (tetri[i - 5] == '#')
					check = 1;
			if (check == 0)
				ft_error();
			check = 0;
		}
	return (1);
}

int		ft_checkcoord(char *tetri, int i)
{
	if (ft_checkpairs(tetri, 0, 0))
		while (tetri[i])
		{
			if (tetri[i] != '#')
				i++;
			else
			{
				if (tetri[i + 1] == '#' && tetri[i + 2] == '#' && i < 18)
					return (1);
				else if (tetri[i + 1] == '#' && tetri[i + 6] == '#' && i < 14)
					return (1);
				else if (tetri[i + 5] == '#' && tetri[i + 6] == '#' && i < 14)
					return (1);
				else if (tetri[i + 5] == '#' && tetri[i + 10] == '#' && i < 10)
					return (1);
				else if (tetri[i + 4] == '#' && tetri[i + 5] == '#' && i < 15)
					return (1);
			}
		}
	return (0);
}

int		ft_checktetri(char *tetri, t_infos *infos)
{
	int		i;

	infos->dots = 0;
	infos->hashtags = 0;
	infos->lines = 0;
	i = 0;
	if (ft_countlines(tetri) == 0)
		return (-1);
	while (i < 20)
	{
		if (tetri[i] == '.')
			infos->dots++;
		if (tetri[i] == '#')
			infos->hashtags++;
		if (tetri[i] == '\n')
			infos->lines++;
		i++;
	}
	if (infos->dots != 12 || infos->hashtags != 4 || infos->lines != 4 || i != 20)
		return (-1);
	i = 0;
	return (ft_checkcoord(tetri, i));
}
