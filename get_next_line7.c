/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:29:11 by alallema          #+#    #+#             */
/*   Updated: 2016/03/18 17:25:23 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char	*ft_clean_buf(char *buf)
{
	int i;

	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (buf);
}
char	*ft_strcchr(char *s, char c)
{
	while (*s != c && *s)
		s++;
	if (*s == c && s++ != NULL && s++ != '\0')
		return(s++);
	return (NULL);
}

int	get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	static char *tmp;
	int ret;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	ret = read(fd, &buf, BUFF_SIZE);
	if (fd == -1 || ret == -1)
		return (-1);
	if (ret == 0 && tmp == NULL)
	{
		ft_putstr("end");
		return (0);
	}
	printf("%s", tmp);
/*	if (ft_strchr(buf, '\n') == NULL)
	{
//		buf[ret] = '\0';
		if (tmp != NULL)
		{
			ft_putchar('a');
			tmp = ft_strjoin(tmp, buf);
		}
		else
		{
			ft_putchar('p');
			tmp = buf;
		}
//		ft_putstr(tmp);
		get_next_line(fd, line);
	}
*/	if (tmp != NULL && ft_strchr(tmp, '\n') != NULL)
	{
		*line = ft_clean_buf(tmp);
		tmp = ft_strcchr(tmp, '\n');
		ft_putchar('b');
		ft_putstr(tmp);
		return (1);
	}
	if (ft_strchr(buf, '\n') != NULL)
	{
		if (tmp != NULL)
			*line = ft_strjoin(tmp, ft_clean_buf(buf));
		else
			*line = ft_clean_buf(buf);
//		buf[ret] = '\0';
		tmp = "lala";
		ft_putchar('c');
//		ft_putchar(*tmp);
		ft_putstr(tmp);
		return (1);
	}
	return (-1);
}
