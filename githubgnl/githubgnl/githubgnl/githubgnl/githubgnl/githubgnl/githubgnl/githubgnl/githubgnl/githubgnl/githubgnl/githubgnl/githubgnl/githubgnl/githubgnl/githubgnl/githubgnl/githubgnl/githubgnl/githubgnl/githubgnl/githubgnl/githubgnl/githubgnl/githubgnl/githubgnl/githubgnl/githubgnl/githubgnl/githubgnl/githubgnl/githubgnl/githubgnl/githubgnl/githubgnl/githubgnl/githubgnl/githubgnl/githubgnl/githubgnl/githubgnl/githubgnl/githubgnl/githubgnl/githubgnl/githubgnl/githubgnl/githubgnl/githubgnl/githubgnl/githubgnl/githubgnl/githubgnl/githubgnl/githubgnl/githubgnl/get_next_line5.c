/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:49:18 by alallema          #+#    #+#             */
/*   Updated: 2016/03/17 16:26:15 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	static char *ret;

	if (fd == -1)
		return (-1);
	read(fd, &buf, BUFF_SIZE)
	if (ft_strchr(buf, '\n') != NULL)
	{
		ret = ft_strchr(buf, '\n')
		ret++;
	}
}
