/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:57:57 by alallema          #+#    #+#             */
/*   Updated: 2016/03/12 17:15:36 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	static char *ret;

	if (fd == -1)
		return (-1);
	ret = (char *)malloc(sizeof(char ) * BUFF_SIZE);
	while (read(fd, &buf, BUFF_SIZE))
	{
		if (ft_strchr(buf, '\n') != NULL)
		{
			ret = ft_strchr(buf, '\n');
			ret++;
			ft_putstr(ret);
			return (1);
		}
	}
//	ft_putstr(*line);
	return (0);
}

