/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:24:20 by alallema          #+#    #+#             */
/*   Updated: 2016/03/18 14:45:37 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_clean(char *buf)
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
	char		buf[BUFF_SIZE];
	static char	*tmp;
	int		ret;
	int		i;

	ret = read(fd, &buf, BUFF_SIZE);
	while (ret > 0)
	{
		if (!ft_strchr(tmp, '\n'))
		{
			*line = ft_clean(tmp);
			tmp = ft_strchr(tmp, '\n');
			tmp++;
			return (1);
		}
		if (!ft_strchr(buf, '\n'))
		{
			tmp = ft_strchr(buf, '\n');
			tmp++;
			*line = ft_strjoin(*line, ft_clean(buf));
			return (1);
		}
		if (ft_strchr(buf, '\n') == NULL)
		{
			*line = ft_strjoin(*line, buf);
		}
	}
	if (ret == 0)
		return (0);
}
