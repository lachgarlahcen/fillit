/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:47:00 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/29 18:18:40 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"
# include "libft/libft.h"

typedef	struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_tetris
{
	char			letter;
	t_point			point[4];
	struct s_tetris	*next;
}				t_tetris;

void			ft_load_tetris(char **line, t_tetris *tetris);
int				ft_nb_bloc(char **line, int i, int j);
int				ft_is_valide(char **line);
int				ft_read_tetris(const int fd, t_tetris *tetris);
t_tetris		*ft_read_all(const int fd);
void			ft_fillit(t_tetris *tetris);
#endif
