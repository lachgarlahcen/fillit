/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 08:43:02 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/21 16:30:25 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_realloc(char **str, int old_size, int new_size)
{
	char *tmp;

	if (new_size == old_size)
		return (*str);
	tmp = malloc(new_size);
	if (tmp == NULL)
		return (NULL);
	if (*str != NULL)
	{
		ft_memcpy(tmp, *str, old_size);
		if (old_size != 0)
			free(*str);
	}
	*str = tmp;
	return (*str + old_size);
}

int		ft_line_size(char *buff)
{
	int n;

	n = 0;
	while (buff[n] != '\n' && buff[n] != '\0')
		n++;
	return (n);
}

int		ft_read_buffer(char *buff, char **line, int *lsize)
{
	char	*ptr;
	char	*ptr2;
	int		l_size;

	l_size = ft_line_size(buff);
	ptr = ft_realloc(line, *lsize, *lsize + l_size + 1);
	*lsize = *lsize + l_size;
	ptr2 = ft_memccpy(ptr, buff, 0x0a, l_size + 1);
	if (ptr2)
	{
		*(ptr2 - 1) = '\0';
		ft_memcpy(buff, buff + l_size + 1, BUFF_SIZE - l_size);
		return (1);
	}
	else
	{
		*(ptr + l_size) = '\0';
		ft_bzero(buff, l_size + 1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	buff[MAX_FILE][BUFF_SIZE + 1];
	int			endline;
	int			readed;
	int			lsize;

	if (fd <= -1 || fd >= MAX_FILE || line == NULL || BUFF_SIZE > 10000000)
		return (-1);
	endline = 0;
	lsize = 0;
	while (!endline)
	{
		if (!ft_strlen(buff[fd]))
		{
			if ((readed = read(fd, buff[fd], BUFF_SIZE)) <= 0)
			{
				if (lsize && readed == 0)
					return (1);
				return (readed);
			}
			buff[fd][readed] = '\0';
		}
		endline = ft_read_buffer(buff[fd], line, &lsize);
	}
	return (1);
}
