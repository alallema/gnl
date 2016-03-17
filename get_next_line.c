/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:57:57 by alallema          #+#    #+#             */
/*   Updated: 2016/03/17 19:56:07 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_clean_buf(char *buf)
{
	int i;

	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (buf);
}

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	static char *ret;

	if (fd == -1)
		return (-1);
//	ret = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
//	ret = ft_strnew((size_t) BUFF_SIZE);
	while (read(fd, &buf, BUFF_SIZE))
	{
		if (ft_strchr(buf, '\n') == NULL)
		{
			*line = ft_strjoin(*line, buf);
		}
		if (ft_strchr(buf, '\n') != NULL)
		{
			ret = ft_strchr(buf, '\n');
			ret++;
			*line = ft_strjoin(*line, ft_clean_buf(buf));
			ft_putstr(*line);
			return (1);
		}
		*line = ft_clean_buf(ret);
		ret = ft_strchr(ret, '\n');
		ret++;
	}
//	ft_putstr(*line);
//	ft_putnbr(r);
	return (0);
}
