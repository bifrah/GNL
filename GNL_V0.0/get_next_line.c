/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:28:57 by bifrah            #+#    #+#             */
/*   Updated: 2021/08/26 13:38:45 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*first_call(char **line, char **stat)
{
	unsigned int	j;
	int				i;
	char			*tmp;

	j = 0;
	i = find_n(*line) + 1;
	tmp = ft_strdup(*line);
	*stat = (char *)malloc(sizeof(char) * (ft_strlen(*line) - i));
	if (!(*stat))
		return (NULL);
	line[0][i] = '\0';
	while (tmp[i])
		stat[0][j++] = tmp[i++];
	stat[0][j] = '\0';
	return (*stat);
}

char	*stat_with_n(char **line, char **stat)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	j = 0;
	*line = ft_strdup(*stat);
	i = find_n(*line) + 1;
	tmp = ft_strdup(*stat);
	free(*stat);
	*stat = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i));
	if (!*stat)
		return (NULL);
	line[0][i] = '\0';
	while (tmp[i])
		stat[0][j++] = tmp[i++];
	stat[0][j] = '\0';
	return (*line);
}

void	*read_me_please(int fd, char *buff, char **line)
{
	int	ret;

	ret = 42;
	while (ret > 0 && ft_strchr(*line, '\n') == NULL)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		*line = ft_strjoin(*line, buff);
		if (ret == 0)
			return (NULL);
	}
	return (*line);
}

void	line_norm(char **line, char **stat)
{
	if (ft_strchr(*stat, '\n') == NULL)
	{
		*line = ft_strdup(*stat);
		free(*stat);
	}
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*stat = NULL;
	char			*line;

	if (read(fd, buff, 0) == -1 || BUFFER_SIZE < -1)
		return (NULL);
	line = ft_strdup("");
	if (stat != NULL)
	{
		if (ft_strchr(stat, '\n') != NULL)
		{
			stat_with_n(&line, &stat);
			return (line);
		}
		line_norm(&line, &stat);
	}
	if (read_me_please(fd, buff, &line) != NULL)
		first_call(&line, &stat);
	else
	{
		stat = NULL;
		free(stat);
	}
	return (line);
}
