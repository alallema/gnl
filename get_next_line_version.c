#include "get_next_line.h"

void ft_strdel(char **as);

char			*ft_check_stock(char *tmp)
{
	int		i;
	char		*s;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	s = ft_strsub(tmp, 0, i);
	ft_strcpy(tmp, &tmp[i + 1]);
	return (s);
}

int			ft_read_fd(const int fd, char *tmp)
{
	char		buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(tmp, '\n'))
			return (ret);
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp;
	int		ret;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(BUFF_SIZE);
	if ((ret = ft_read_fd(fd, tmp)) < 0)
		return (-1);
	if (ret == 0 && tmp[0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	ft_putstr(tmp);
	*line = ft_check_stock(tmp);
	return (1);
}
