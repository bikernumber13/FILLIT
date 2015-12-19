/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:14:43 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 18:40:52 by maboukra         ###   ########.fr       */
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
	return (0);
}
