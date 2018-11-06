/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:47:00 by yez-zain          #+#    #+#             */
/*   Updated: 2018/11/06 14:17:40 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef	struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_tetris
{
	char			letter;
	t_point			point[4];
	t_point			max;
	struct s_tetris	*next;
}				t_tetris;

int				ft_read_tetris(const int fd, t_tetris *tetris);
t_tetris		*ft_read_all(const int fd);
char			**tab_malloc(int r, int c);
void			ft_init_tab(char **tab, int size);
void			ft_put_shape(char **tab, int size);
char			**add_bord(char **tab, int size);
int				gess_bord(int len);
int				ft_sqrt(int nb);
int				list_lenght(t_tetris *list);
void			solve(t_tetris *t);
int				fillit(t_tetris *list, char **tab, int size, t_point *a);
t_point			add_max(t_tetris *list);
void			ft_remove(char **tab, t_tetris *list, t_point *a);
t_point			*init_p(t_point *a);
void			ft_list_remove(t_tetris *list);

#endif
