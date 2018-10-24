/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:47:00 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/24 22:39:44 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"
# include "libft/libft.h"

# define READ_SUCCES 1
# define READ_ENDED 0
# define READ_FAILURE -1
# define END_OF_LIST 2

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

int				ft_read_tetris(const int fd, t_tetris *tetris);
t_tetris		*ft_read_all(const int fd);

#endif
