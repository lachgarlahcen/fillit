/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:06:16 by llachgar          #+#    #+#             */
/*   Updated: 2018/11/03 00:39:55 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int x)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (x == 0 || x == 1)
		return (x);
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

void	ft_list_remove(t_tetris *list)
{
	t_tetris	*t;

	if (list == NULL)
		return ;
	t = list;
	while (list)
	{
		list = list->next;
		free(t);
		t = list;
	}
}

int		count_tab_points(char *tab, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (tab[i] == '.')
			count++;
		i++;
	}
	return (count);
}

int		optimal_check(char **tab, int size, int len)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += count_tab_points(tab[i], size);
		i++;
	}
	if (count < (len * 4))
		return (0);
	return (1);
}
