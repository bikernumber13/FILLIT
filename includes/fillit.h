/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboukra <maboukra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:20:57 by maboukra          #+#    #+#             */
/*   Updated: 2015/12/30 11:17:12 by mbouhier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_tris
{
	int				coord[4][2];
	int				used;
	int				ymax;
	int				xmax;
	int				xmin;
	char			let;
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
	int				c_n;
	int				x;
	int				y;
	int				sides;
	int				new_grid;
	char			**grid;
	t_tris			*first;
	t_tris			*link;
}					t_infos;

void				ft_error(void);
void				ft_grid(t_infos *infos);
int					ft_read(char *filename, t_infos *infos);
int					ft_checktetri(char *buf, t_infos *infos);
void				ft_printgrid(t_infos *infos);
int					ft_solve(t_infos *infos);
t_infos				*ft_create_infos(void);
void				ft_tris_push_back(t_infos *infos, char *tetri);
int					ft_check_slot(t_infos *infos, t_tris *tris, int y, int x);
int					ft_final_c(t_infos *infos, t_tris *tris, int y, int x);
int					ft_check_used(t_infos *infos);
int					ft_write_tetri(t_infos *infos, t_tris *tris, int y, int x);
int					ft_y(t_infos *infos, int y, int x);
int					ft_x(t_infos *infos, int x);

#endif
