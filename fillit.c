/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:01:03 by llachgar          #+#    #+#             */
/*   Updated: 2018/11/02 23:38:56 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_point		*test_add(t_tetris *list, int size, char **tab, t_point *a)
{
	int i;

	if ((list->max.x + a->x) >= size || (list->max.y + a->y) > size)
		return (NULL);
	if ((list->max.y + a->y) == size)
	{
		a->y = 0;
		a->x++;
	}
	i = -1;
	while (++i < 4)
	{
		if (tab[list->point[i].x + a->x][list->point[i].y + a->y] != '.')
		{
			a->y++;
			return (test_add(list, size, tab, a));
		}
	}
	return (a);
}

void		ft_add_shape(char **tab, t_tetris *list, t_point *a)
{
	int		i;
	char	c;

	i = 0;
	c = list->letter;
	while (i < 4)
	{
		tab[list->point[i].x + a->x][list->point[i].y + a->y] = c;
		i++;
	}
}

void		ft_remove(char **tab, t_tetris *list, t_point *a)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab[list->point[i].x + a->x][list->point[i].y + a->y] = '.';
		i++;
	}
}

int			ft_change_place(char **tab, t_tetris *list, int size, t_point *a)
{
	if ((a = test_add(list, size, tab, a)))
	{
		ft_add_shape(tab, list, a);
		return (1);
	}
	else
		return (0);
}

int			fillit(t_tetris *list, char **tab, int size, t_point *x)
{
	t_point *a;

	a = (t_point*)malloc(sizeof(t_point) * 1);
	a->x = 0;
	a->y = 0;
	if (list == NULL)
	{
		ft_put_shape(tab, size);
		exit(1);
	}
	if ((x = test_add(list, size, tab, x)) != NULL)
	{
		ft_add_shape(tab, list, x);
		if (fillit(list->next, tab, size, a) == 0)
		{
			ft_remove(tab, list, x);
			x->y++;
			if (!fillit(list, tab, size, x))
				return (0);
		}
	}
	return (0);
}
