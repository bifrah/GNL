#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*read_me_please(int fd, char *buff)
{
	char	*tmp;
	int		ret;

	ret = 42;
	tmp = ft_strdup("");
	while (ret > 0 && ft_strchr(tmp, '\n') == NULL)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
		printf("stat : %s\n", tmp);
		if (ret == 0)
			return (NULL);
	}
	return (tmp);
}

char	*stat_with_n(char **stat)
{
	unsigned int	i;
	unsigned int	j;
	char			*line;
	char			tmp[BUFFER_SIZE];

	if (!*stat)
		return (NULL);
	i = 0;
	j = find_n(*stat) + 1;
	while (i < j)
	{
		tmp[i] = stat[0][i];
		i++;
	}
	tmp[i] = '\0';
	line = ft_strdup(tmp);
	printf("line : %s\n", line);
	j = 0;
	while (stat[0][i])
		stat[0][j++] = stat[0][i++];
	stat[0][j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (read(fd, buff, 0) == -1)
		return (NULL);
	if (ft_strchr(stat, '\n') == NULL)
	{
		tmp = ft_strdup("");
		tmp = read_me_please(fd, buff);
		stat = ft_strjoin(tmp, stat);
	}
	if (ft_strchr(stat, '\n') != NULL)
	{
		line = stat_with_n(&stat);
	}
	return (line);
}