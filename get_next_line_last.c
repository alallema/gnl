/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:22:12 by alallema          #+#    #+#             */
/*   Updated: 2016/04/02 20:07:36 by alallema         ###   ########.fr       */
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

char			*ft_check_stock(char *s)
{
	int 		i;
	char		*s2;

	i = 0;
	if (!s)
		return (NULL);
	s = ft_strdup(s);
	while (s[i] != '\n' && s[i])
		i++;
	s2 = ft_strnew(i + 1);
	s2 = ft_strncpy(s2, s, (size_t) i);
	s2[i + 1] = '\0';
	i++;
	if (s[i])
	{
		s = ft_strchr(s, '\n');
		s++;
	}
	else
	{
		s = NULL;
	}
/*	if (!ft_strchr(tmp, '\n') && s[i])
	{
		ft_putchar('d');
		*line = ft_strjoin(tmp, s);
		if (ft_strchr(*line, '\n'))
			*ft_strchr(*line, '\n') = '\0';
		tmp = ft_strchr(s, '\n');
		tmp++;
	}
*/	return(s2);
}

int				ft_read(const int fd, char *tmp)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, &buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ret < 0 || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_strjoin(tmp, buf);
	if (ft_strchr(tmp, '\n'))
	{
//		ft_putstr("ret1");
		return (ret);
	}
	if (!ft_strchr(tmp, '\n'))
	{
//		ft_putstr("ret2");
		ft_read(fd, tmp);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp;
	int			ret;

	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || tmp == NULL)
		return (-1);
	if (ft_strchr(tmp, '\n'))
	{
//		ft_putstr("get1");
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
//		*line = ft_check_stock(tmp);
		return (1);
	}
	if (!ft_strchr(tmp, '\n'))
	{
		ret = ft_read(fd, tmp);
//		ft_putstr("get2");
//		*line = ft_check_stock(tmp);
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		if (ret == 0 && !*tmp)
		{
//			free(line);
			return (0);
		}
		if (ret < 0)
			return (-1);
		return(1);
	}
	return (0);
}
