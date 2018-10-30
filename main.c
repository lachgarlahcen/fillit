/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:23:43 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/30 08:58:27 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int	main(int argc, char *argv[])
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
	ft_fillit(t);
	return (0);
}
