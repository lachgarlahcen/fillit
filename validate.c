/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:46:44 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/29 17:51:19 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_load_tetris(char **line, t_tetris *tetris)
{
	int		i;
	int		j;
	t_point	min;

	i = -1;
	j = 0;
	min.x = 4;
	min.y = 4;
	while (++i < 16)
	{
		if (line[i / 4][i % 4] == '#')
		{
			tetris->point[j].x = i / 4;
			tetris->point[j].y = i % 4;
			min.x = (min.x > tetris->point[j].x) ? tetris->point[j].x : min.x;
			min.y = (min.y > tetris->point[j].y) ? tetris->point[j].y : min.y;
			j++;
		}
	}
	j = -1;
	while (++j < 4)
	{
		tetris->point[j].x -= min.x;
		tetris->point[j].y -= min.y;
	}
}

int			ft_nb_bloc(char** line, int i, int j)
{
	int nb;

	nb = 0;
	if (i - 1 >= 0)
		if (line[i - 1][j] == '#')
			nb++;
	if (j - 1 >= 0)
		if (line[i][j - 1] == '#')
			nb++;
	if (i + 1 <= 3)
		if (line[i + 1][j] == '#')
			nb++;
	if (j + 1 <= 3)
		if (line[i][j + 1] == '#')
			nb++;
	return (nb);
}

int			ft_is_valide(char **line)
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

int			ft_read_tetris(const int fd, t_tetris *tetris)
{
	int		i;
	char	*line[5];
	int		ret;

	if (get_next_line(fd, &line[0]) == 0 || ft_strlen(line[0]) != 4)
		return (-1);
	i = 0;
	while (++i < 4)
	{
		if(get_next_line(fd, &line[i]) == 0 || ft_strlen(line[i]) != 4)
			return (-1);
	}
	if ((ret = get_next_line(fd, &line[4])) == 0 || ft_strlen(line[4]) == 0)
	{
		if (ft_is_valide(line))
			ft_load_tetris(line, tetris);
		else
			return (-1);
		if (ret == 1 && ft_strlen(line[4]) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}

t_tetris	*ft_read_all(const int fd)
{
	t_tetris	*list;
	t_tetris	*elem;
	int			ret;
	char		c;

	c = 'A';
	if (!(elem = ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	list = elem;
	while ((ret = ft_read_tetris(fd, elem)) >= 0)
	{
		elem->letter = c++;
		if (ret == 0)
			return (list);
		elem->next = ft_memalloc(sizeof(t_tetris));
		elem = elem->next;
	}
	return (NULL);
}
