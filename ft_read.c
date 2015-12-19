/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:26:35 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 15:35:13 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

t_infos	*ft_create_infos(void)
{
	t_infos	*infos;

	if (!(infos = (t_infos *)malloc(sizeof(*infos))))
		return (NULL);
	infos->first = NULL;
	infos->nb_used = 0;
	infos->nb_tetri = 0;
	infos->sides = 2;
	return (infos);
}

int		ft_read(char *filename, t_infos *infos)
{
	int		fd;
	char	*buf;

	if (!(fd = open(filename, O_RDONLY)))
		ft_error();
	if (!(buf = (char *)malloc(sizeof(*buf) * 21)))
		ft_error();
	while (read(fd, buf, 21))
	{
		if (ft_checktetri(buf, infos) == -1)
			ft_error();
		ft_tris_push_back(infos, buf);
	}
	if (infos->nb_tetri == 0)
		ft_error();
	if (close(fd) == -1)
		ft_error();
	return (0);
}
