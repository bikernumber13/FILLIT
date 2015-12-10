/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:17:32 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/10 19:31:17 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void ft_fill(t_info *infos)
{
	infos->tab[0] = "####\n....\n....\n....\n\0";
	infos->tab[1] = "#...\n#...\n#...\n#...\n\0";
	infos->tab[2] = "##..\n##..\n....\n....\n\0";
	infos->tab[3] = "###.\n.#..\n....\n....\n\0";
	infos->tab[4] = ".#..\n##..\n.#..\n....\n\0";
	infos->tab[5] = ".#..\n###.\n....\n....\n\0";
	infos->tab[6] = "#...\n##..\n#...\n....\n\0";
	infos->tab[7] = "###.\n#...\n....\n....\n\0";
	infos->tab[8] = "##..\n.#..\n.#..\n....\n\0";
	infos->tab[9] = "..#.\n###.\n....\n....\n\0";
	infos->tab[10] = "#...\n#...\n##..\n....\n\0";
	infos->tab[11] = "###.\n..#.\n....\n....\n\0";
	infos->tab[12] = ".#..\n.#..\n##..\n....\n\0";
	infos->tab[13] = "#...\n###.\n....\n....\n\0";
	infos->tab[14] = "##..\n#...\n#...\n....\n\0";
	infos->tab[15] = "##..\n.##.\n....\n....\n\0";
	infos->tab[16] = ".#..\n##..\n#...\n....\n\0";
	infos->tab[17] = ".##.\n##..\n....\n....\n\0";
	infos->tab[18] = "#...\n##..\n.#..\n....\n\0";
	infos->tab[19] = "\0";
}

int		ft_check(t_list *lst, t_info *infos)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (tmp = (t_list)malloc(sizeof(t_list)))
		tmp = infos->first;
	ft_fill(infos);
	while (t_infos->tab[i])
	{
		if (ft_strcmp(lst->tetri, t_infos->tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
