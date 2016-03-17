/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:19:10 by alallema          #+#    #+#             */
/*   Updated: 2016/03/17 16:26:09 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	static char *ret;

	if (fd == -1)
		return (-1);
	ret = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	line = (char **)malloc(sizeof(char *) * (BUFF_SIZE + 1));
//	*line = ft_strnew((size_t) BUFF_SIZE);

	while (read(fd, &buf, BUFF_SIZE))
		if (ft_strchr(buf, '\n'), BUFF_SIZE == NULL)
		{
//			get_next_line(fd, ft_strjoin(*line, buf));
			*line = ft_strjoin(*line, buf);
		}
		if (ft_strchr(buf, '\n') != NULL)
		{
			return (1);
		}
	return (0);
}
