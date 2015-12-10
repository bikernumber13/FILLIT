/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:30:18 by mbouhier          #+#    #+#             */
/*   Updated: 2015/12/10 20:52:05 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_read(t_list *lst, char *file)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[21];
	t_list	*tmp;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	while ((ret = read(fd, buf, 21)))
	{
		if (i == 0)
		{
			if (!(lst->tetri = (char*)malloc(sizeof(char) * 21)))
				exit(EXIT_FAILURE);
			ft_strcpy(lst->tetri, buf);
			tmp = lst;
			i = 1;
		}
		else
		{
			if (!(tmp->next = (t_list*)malloc(sizeof(t_list))))
				exit(EXIT_FAILURE);
			if (!(tmp->next->tetri = (char*)malloc(sizeof(char) * 21)))
				exit(EXIT_FAILURE);
			ft_strcpy(tmp->next->tetri, buf);
			tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	while (lst)
	{
		printf("%s", lst->tetri);
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	t_list	*lst;
	//	t_info	*infos;

	if (ac == 2)
	{
		if (!(lst = (t_list*)malloc(sizeof(t_list))))
			exit(EXIT_FAILURE);
		//		if (!(infos = (t_info*)malloc(sizeof(*infos))) == NULL)
		//			exit(EXIT_FAILURE);
		ft_read(lst, av[1]);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}
