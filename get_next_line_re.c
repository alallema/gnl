/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:22:12 by alallema          #+#    #+#             */
/*   Updated: 2016/03/19 16:37:17 by alallema         ###   ########.fr       */
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

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*tmp;
	int ret;

	ret = read(fd, &buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (fd < 0 || ret < 0)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if (tmp == NULL)
		return (-1);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	if (*tmp && ret == 0)
	{
		*line = ft_clean(tmp);
		tmp = ft_strcchr(tmp);
		return (1);
	}
	if (ft_strchr(buf, '\n'))
	{
		*line = ft_strjoin(tmp, ft_clean(buf));
		tmp = ft_strcchr(buf);
		return (1);
	}
	if (!ft_strchr(buf, '\n') && ret >= BUFF_SIZE)
	{
		tmp = ft_strjoin(tmp, buf);
		get_next_line(fd, line);
	}
	return (-1);
}
/*t_list	*ft_create_list(void)
{
	t_list	*list;
	char	buf;
	int		ret;

	ret = read(0, &buf, 1);
	if (ret != 0)
		list = ft_create_elem(buf);
	else
		return (0);
	while (ret != 0)
	{
		ret = read(0, &buf, 1);
		ft_list_push_back(&list, buf);
	}
	return (list);
}
*/
