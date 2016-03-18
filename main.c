/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:03:40 by alallema          #+#    #+#             */
/*   Updated: 2016/03/17 18:33:18 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int	get_next_line(const	int fd, char	**line);

int	main(int ac, char **av)
{
	int fd;
	char *line;
	int get;

	if (ac < 2)
	{
		ft_putstr("erreur");
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("erreur fd");
		return (1);
	}
	line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((get = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putnbr(get);
	}
	close(fd);
	return (0);
}
