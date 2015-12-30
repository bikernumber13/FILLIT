/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 14:55:39 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/28 17:01:48 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_x(t_infos *infos, int x)
{
	if (x + 1 == infos->sides)
		x = 0;
	else
		x++;
	return (x);
}

int		ft_y(t_infos *infos, int y, int x)
{
	if (x + 1 == infos->sides)
		y++;
	return (y);
}

int		ft_solve(t_infos *infos)
{
	if (ft_check_used(infos) == 0)
		return (0);
	return (1);
}
