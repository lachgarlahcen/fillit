/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 23:27:36 by llachgar          #+#    #+#             */
/*   Updated: 2018/11/03 00:26:36 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			list_lenght(t_tetris *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void		ft_put_shape(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

t_point		*init_p(t_point *a)
{
	a->x = 0;
	a->y = 0;
	return (a);
}

void		solve(t_tetris *t)
{
	int			fd;
	char		**tab;
	t_point		*a;

	a = (t_point*)malloc(sizeof(t_point) * 1);
	a = init_p(a);
	fd = gess_bord(list_lenght(t));
	tab = tab_malloc(fd + 1, fd);
	ft_init_tab(tab, fd);
	while (fillit(t, tab, fd, a) == 0)
	{
		fd++;
		a = init_p(a);
		tab = add_bord(tab, fd);
	}
}

t_point		add_max(t_tetris *list)
{
	int		i;
	t_point max;

	i = 0;
	max.x = 0;
	max.y = 0;
	while (i < 4)
	{
		if (list->point[i].x > max.x)
			max.x = list->point[i].x;
		if (list->point[i].y > max.y)
			max.y = list->point[i].y;
		i++;
	}
	return (max);
}
