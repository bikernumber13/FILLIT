/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:26:35 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/21 13:56:18 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

t_infos		*ft_create_infos(void)
{
	t_infos	*infos;

	if (!(infos = (t_infos *)malloc(sizeof(*infos))))
		return (NULL);
	infos->first = NULL;
	infos->nb_used = 0;
	infos->nb_tetri = 0;
	infos->sides = 2;
	infos->new_grid = 0;
	infos->c_n = 0;
	return (infos);
}

void		ft_count_n(char *buf, t_infos *infos)
{
	int	i;

	i = 0;
	while (i < 21)
	{
		if (buf[i] == '\n')
			infos->c_n++;
		i++;
	}
}

int			ft_read(char *filename, t_infos *infos)
{
	int		fd;
	char	*buf;
	int		j;

	if (!(fd = open(filename, O_RDONLY)))
		ft_error();
	if (!(buf = (char *)malloc(sizeof(*buf) * 21)))
		ft_error();
	while ((j = read(fd, buf, 21)))
	{
		buf[j] = '\0';
		ft_count_n(buf, infos);
		if (ft_checktetri(buf, infos) == -1)
			ft_error();
		ft_tris_push_back(infos, buf);
	}
	if (((infos->nb_tetri * 5) - 1) != infos->c_n)
		ft_error();
	if (infos->nb_tetri == 0 || infos->nb_tetri > 26)
		ft_error();
	if (close(fd) == -1)
		ft_error();
	return (0);
}
