/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:46:44 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/24 21:06:17 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_load_tetris(char **line, t_list *tetris)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		if (line[i / 4][i % 4] == '#')
		{
			tetris->point[j].x = i / 4;
			tetris->point[j].y = i % 4;
			j++;
		}
		i++;
	}
}

int		ft_nb_bloc(char** line, int i, int j)
{
	int nb;

	if (i - 1 >= 0)
		if (line[i - 1][j] == '#')
			nb++;
	if (j - 1 >= 0)
		if (line[i][j - 1] == '#')
			nb++;
	if (i + 1 <= 3)
		if (line[i + 1][j] == '#')
			n++;
	if (j + 1 <= 3)
		if (line[i][j + 1] == '#')
			nb++;
	return (nb);
}

int		ft_is_valide(char **line)
{
	int	nb_empty;
	int	nb_blocs;
	int	i;

	i = 0;
	nb_empty = 0;
	nb_blocs = 0;
	while (i < 16)
	{
		if (line[i / 4][i % 4] == '.')
			nb_empty++;
		else if (line[i / 4][i % 4] == '#')
		{
			if (ft_nb_bloc(line, i / 4, i % 4) == 0
					|| ft_nb_bloc(line, i / 4, i % 4) == 4)
				return (0);
			nb_blocs++;
		}
		else
			return (0);
		i++;
	}
	if (nb_blocs != 4 || nb_empty != 12)
		return (0);
	return (1);
}

int		ft_read_tetris(const int fd, t_tetris *tetris)
{
	int		i;
	char	*line[5];

	if (get_next_line(fd, &line[0]) == 0)
		return (-1);
	if (ft_strlen(line[0]) != 4)
		return (-1);
	i = 0;
	while (i < 3)
	{
		if(get_next_line(fd, &line[i]) == 0 || ft_strlen(line[i]) != 4)
			return (-1);
		i++;
	}
	if (get_next_line(fd, &line[4]) == 0 || ft_strlen(line[4]) == 0)
	{
		if (ft_is_valide(line))
			ft_load_tetris(line, tetris);
		else
			return (-1);
		return (1);
	}
	else
		return (-1);
}
