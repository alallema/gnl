/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:10:30 by alallema          #+#    #+#             */
/*   Updated: 2016/03/12 17:53:51 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	ft_read_file()
{
	char buf[BUFF_SIZE];

	while (read(fd, &buf, BUFF_SIZE))
	{

	}
}

int	get_next_line(const int fd, char **line)
{
	static char	*ret;

	if (fd == -1)
		return (-1);
	if (*ret == NULL)
		while (read(fd, &buf, BUFF_SIZE))
		{
		}
	else

}
