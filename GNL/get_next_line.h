/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 08:40:52 by yez-zain          #+#    #+#             */
/*   Updated: 2018/10/24 09:42:23 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FILE 4864
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

char	*ft_realloc(char **str, int old_size, int new_size);

int		ft_line_size(char *buff);

int		ft_read_buffer(char *buff, char **line, int *lsize);

int		get_next_line(const int fd, char **line);

#endif
