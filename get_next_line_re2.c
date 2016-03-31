/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:22:12 by alallema          #+#    #+#             */
/*   Updated: 2016/03/31 17:52:36 by alallema         ###   ########.fr       */
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
char	*ft_clean_cut(char *s, char *tmp)
{
	int i;
	int j;

	i = 0;
	if (!s)
		return (NULL);
	s = strdup(s);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		j = i;
		j++;
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
	}
	if (tmp != NULL)
		tmp = ft_strdup(&tmp[j]);
	return (s);
}

int				ft_read(const int fd, char *tmp, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int ret;

	ret = read(fd, &buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ret < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (*tmp && ret == 0)
	{
			*line = ft_clean(tmp);
//			*line = ft_strdup(tmp);
//			*ft_strchr(*line, '\n') = '\0';
			tmp = ft_strjoin(ft_strcchr(tmp), buf);
			return (1);
	}
	else if (ret == 0)
		return (0);
	else if (ft_strchr(buf, '\n'))
	{
		*line = ft_strjoin(tmp, ft_clean(buf));
		tmp = ft_strcchr(buf);
	}
	else if (!ft_strchr(buf, '\n'))
	{
		tmp = ft_strjoin(tmp, buf);
		get_next_line(fd, line);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp;

	if (!tmp)
		ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || tmp == NULL)
		return (-1);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_strdup(tmp);
		*ft_strchr(*line, '\n') = '\0';
		tmp = ft_strchr(tmp, '\n');
		tmp++;
		return (1);
	}
	if (!ft_strchr(tmp, '\n'))
		return (ft_read(fd, tmp, line));
	return (0);
}
/*
int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*tmp;
	int ret;

	ret = read(fd, &buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (!tmp && ret != 0)
		tmp = ft_strnew(BUFF_SIZE);
	if (fd < 0 || ret < 0 || BUFF_SIZE <= 0 || !line || tmp == NULL)
		return (-1);
	if (ft_strchr(tmp, '\n') || (*tmp && ret == 0))
	{
			*line = ft_clean(tmp);
//			*line = ft_strdup(tmp);
//			*ft_strchr(*line, '\n') = '\0';
			tmp = ft_strjoin(ft_strcchr(tmp), buf);
	}
	else if (ret == 0)
		return (0);
	else if (ft_strchr(buf, '\n'))
	{
		*line = ft_strjoin(tmp, ft_clean(buf));
		tmp = ft_strcchr(buf);
	}
	else if (!ft_strchr(buf, '\n'))
	{
		tmp = ft_strjoin(tmp, buf);
		get_next_line(fd, line);
	}
	return (1);
}*/
