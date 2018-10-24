/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:47:00 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/24 17:16:30 by yez-zain         ###   ########.fr       */
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
	char		letter;
	t_point		point[4];
	t_tetris	*next;
}				t_tetris;

#endif
