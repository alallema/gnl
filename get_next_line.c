/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:14:56 by alallema          #+#    #+#             */
/*   Updated: 2016/04/07 19:08:40 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_check_stock(char *tmp)
{
	size_t		i;
	char		*s;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	s = ft_strsub(tmp, 0, i);
	ft_strcpy(tmp, &tmp[i + 1]);
	tmp[ft_strlen(tmp) + 1] = '\0';
	return (s);
}

static char		*ft_fix_join(char *s, char *buf)
{
	char		*tmp;

	tmp = s;
	s = ft_strjoin(tmp, buf);
	free(tmp);
	return (s);
}

static int		ft_read(const int fd, char **tmp, char ***line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*tmp = ft_fix_join(*tmp, buf);
		if (ft_strchr(*tmp, '\n') || ret < BUFF_SIZE)
		{
			**line = ft_check_stock(*tmp);
			return (1);
		}
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || fd > 256)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_check_stock(tmp);
		return (1);
	}
	if ((ret = ft_read(fd, &tmp, &line)) == 1)
		return (1);
	if (*tmp && ret == 0)
	{
		*line = ft_check_stock(tmp);
		return (1);
	}
	if (ret < 0)
		return (-1);
	ft_strdel(line);
	return (0);
}
