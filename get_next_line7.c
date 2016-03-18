#include "get_next_line.h"
#include "libft.h"

char	*ft_clean_buf(char *buf)
{
	int i;

	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (buf);
}
int	get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	static char *tmp;
	int ret;

	ret = read(fd, &buf, BUFF_SIZE);
	if (fd == -1)
		return (-1);
	if (ret == 0)
		return (0);
	if (ft_strchr(buf, '\n') == NULL)
	{
//		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		get_next_line(fd, line);
	}
	if (!ft_strchr(tmp, '\n'))
	{
		tmp = ft_strchr(buf, '\n');
		*line = ft_strjoin(*line, ft_clean_buf(buf));
		return (1);
	}
	return (-1);
}
