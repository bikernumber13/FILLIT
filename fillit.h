/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:20:57 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/18 15:36:08 by maboukra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_tris
{
	int				coord[4][2];
	int				used;
	char			letter;
	int				Ymax;
	int				Xmax;
	int				Xmin;
	struct s_tris	*next;
}					t_tris;

typedef struct		s_infos
{
	int				nb_tetri;
	int				nb_used;
	int				dots;
	int				hashtags;
	int				lines;
	int				hash;
	int				x;
	int				y;
	int				sides;
	char			**grid;
	t_tris			*first;
	t_tris			*link;
}					t_infos;

void				ft_putstr(char *str);
void				ft_putendl(char *str);
void				ft_error(void);
void				ft_grid(t_infos *infos);
void				ft_tris_push_back(t_infos *infos, char *tetri);
int					ft_read(char *filename, t_infos *infos);
int					ft_checktetri(char *buf, t_infos *infos);
void				ft_printgrid(t_infos *infos);
int					ft_solve(t_infos *infos);
t_infos				*ft_create_infos(void);

#endif
