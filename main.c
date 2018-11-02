/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:23:43 by yez-zain          #+#    #+#             */
/*   Updated: 2018/11/03 00:26:33 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init_tab(char **tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
}

char	**tab_malloc(int r, int c)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char*) * r);
	i = 0;
	while (i < r)
	{
		tab[i] = (char*)malloc(c);
		i++;
	}
	return (tab);
}

char	**add_bord(char **tab, int size)
{
	int i;

	i = -1;
	free(tab);
	tab = tab_malloc(size + 1, size);
	ft_init_tab(tab, size);
	return (tab);
}

int		gess_bord(int len)
{
	int bord;

	if (len == 6 || len == 19 || len == 12)
		bord = ft_sqrt(len * 4) + 2;
	else if (len == 4 || len == 1)
		bord = ft_sqrt(len * 4);
	else
		bord = ft_sqrt(len * 4) + 1;
	return (bord);
}

int		main(int argc, char *argv[])
{
	int			fd;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	if (argc != 2)
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" tetris_list_file");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(t = ft_read_all(fd)))
	{
		ft_putendl("error");
		exit(1);
	}
	close(fd);
	solve(t);
	return (0);
}
