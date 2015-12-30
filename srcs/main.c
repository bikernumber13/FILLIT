/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:14:43 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/30 11:20:51 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_infos *infos;

	if (ac == 2)
	{
		infos = ft_create_infos();
		ft_read(av[1], infos);
		ft_grid(infos);
		ft_printgrid(infos);
	}
	else
		ft_error();
	return (0);
}
