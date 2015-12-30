/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:18:30 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 15:20:08 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printgrid(t_infos *infos)
{
	int i;

	i = 0;
	while (infos->grid[i])
		ft_putendl(infos->grid[i++]);
}
