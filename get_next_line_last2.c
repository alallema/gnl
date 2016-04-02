/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:14:56 by alallema          #+#    #+#             */
/*   Updated: 2016/04/02 20:51:00 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_clean(char *s)
{
	int			i;

	i = 0;
	s = ft_strdup(s);
	while (s[i] && s[i] != '\n')
		i++;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}

char			*ft_strcchr(char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	s = ft_strdup(s);
	while (s[i] != '\n' && s[i])
		i++;
	i++;
	return (&s[i]);
}

/*void			ft_read_file(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int ret;

	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!ft_strchr(buf, '\n') && ret >= BUFF_SIZE)
			tmp[fd] = ft_strjoin(tmp[fd], buf);
		if (ft_strchr(buf, '\n') || ret < BUFF_SIZE)
		{
			*line = ft_strjoin(tmp[fd], ft_clean(buf));
			tmp[fd] = ft_strcchr(buf);
			return (*line);
		}
	}
	if (*tmp[fd] && ret == 0)
	{
		*line = ft_clean(tmp[fd]);
		tmp[fd] = ft_strcchr(tmp[fd]);
		return (*line);
	}
	if (ret < 0)
		return (NULL);
}
*/
int				ft_read(const int fd, char *tmp)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ret < 0 || BUFF_SIZE <= 0)
		return (-1);
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(tmp, '\n'))
		{
//		ft_putstr("ret1");
			return (ret);
		}
//		ft_putstr("ret2");
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	if ((ret = ft_read(fd, tmp)) > 0)
	{
			*line = ft_clean(tmp);
			tmp = ft_strcchr(tmp);
//		return (1);
//			get_next_line(fd, line);
		return (1);
	}
	if (*tmp && ret == 0)
	{
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}
/*
int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*tmp;
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!ft_strchr(buf, '\n') && ret >= BUFF_SIZE)
			tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(buf, '\n') || ret < BUFF_SIZE)
		{
			*line = ft_strjoin(tmp, ft_clean(buf));
			tmp = ft_strcchr(buf);
			return (1);
		}
	}
	if (*tmp && ret == 0)
	{
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}
*/
