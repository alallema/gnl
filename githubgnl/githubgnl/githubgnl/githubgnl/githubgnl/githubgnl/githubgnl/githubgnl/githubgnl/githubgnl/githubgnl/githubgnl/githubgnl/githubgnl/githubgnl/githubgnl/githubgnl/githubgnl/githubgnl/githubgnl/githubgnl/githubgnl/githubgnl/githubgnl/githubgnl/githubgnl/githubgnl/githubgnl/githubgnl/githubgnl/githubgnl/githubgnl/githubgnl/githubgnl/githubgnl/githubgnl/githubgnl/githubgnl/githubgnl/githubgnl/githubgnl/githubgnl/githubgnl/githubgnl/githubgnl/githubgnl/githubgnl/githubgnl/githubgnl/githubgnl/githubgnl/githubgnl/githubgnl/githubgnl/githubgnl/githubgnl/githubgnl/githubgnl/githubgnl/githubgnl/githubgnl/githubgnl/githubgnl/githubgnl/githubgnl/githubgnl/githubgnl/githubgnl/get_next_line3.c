/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:38:35 by alallema          #+#    #+#             */
/*   Updated: 2016/03/12 18:53:44 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	get_next_line(const int	fd, char	**line)
{
	char	buf[BUFF_SIZE];
	static t_list *t_list;

	if (fd == -1)
		return (-1);
	if (read(fd, &buf, BUFF_SIZE))
		t_list = ft_lstnew((char *) buf, (int) BUFF_SIZE);
	while (read(fd, &buf, BUFF_SIZE))
	{
		ft_lstpushback(&t_list, (char *) buf, (int) BUFF_SIZE);
	}
	return (0);
}
/*
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void const *content, size_t content_size)
*/
