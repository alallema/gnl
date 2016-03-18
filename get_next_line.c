/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:14:56 by alallema          #+#    #+#             */
/*   Updated: 2016/03/18 19:49:43 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_clean(char *s)
{
	int i;

	i = 0;
	s = ft_strdup(s);
	while (s[i] && s[i] != '\n')
		i++;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	return(s);
}

char	*ft_strcchr(char *s)
{
	int i;

	i = 0;
	s = ft_strdup(s);
	while(s[i] != '\n' && s[i])
		i++;
	i++;
		return(&s[i]);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*tmp;
	int			ret;
	char		*s;

	if (!tmp)
		tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd == -1)
		return(-1);
	if (ft_strchr(tmp, '\n'))
	{
		ft_putchar('t');
		ft_putchar('\n');
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	while ((ret = read (fd, &buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
//		tmp = ft_strjoin(tmp, buf);
		if (!ft_strchr(buf, '\n'))
		{
			ft_putchar('a');
			ft_putchar('\n');
			tmp = ft_strjoin(tmp, buf);
//			ft_putstr(tmp);
		}
		if (ft_strchr(buf, '\n'))
		{
//			ft_putstr(buf);
			ft_putchar('b');
			ft_putchar('\n');
			*line = ft_strjoin(tmp, ft_clean(buf));
			tmp = ft_strcchr(buf);
//			ft_putstr(tmp);
			return (1);
		}
	}
	return(0);
}
