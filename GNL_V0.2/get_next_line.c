/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:28:57 by bifrah            #+#    #+#             */
/*   Updated: 2021/09/08 16:27:37 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*first_call(char *line, char *stat)
{
	unsigned int	j;
	int				i;
	char			*tmp;

	i = find_n(line);
	tmp = ft_strdup(line);
	line[i + 1] = '\0'; // SOUCIS ICI
	i++;
	j = 0;
	while (tmp[i])
		stat[j++] = tmp[i++];
	stat[j] = '\0';
	free(tmp);
	return (line);
}

char	*stat_with_n(char *line, char *stat)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	j = 0;
	line = ft_strjoin(line, stat);
	//printf("On a > %s", line);
	i = find_n(line);
	tmp = ft_strdup(stat);
	i++;
	line[i++] = '\0';
	i--;
	while (tmp[i])
		stat[j++] = tmp[i++];
	stat[j] = '\0';
	free(tmp);
	return (line);
}

char	*ft_last_line(char *line, char *stat)
{
	/*euh...alors ici on doit si ret == 0 on a 2 cas
	soit on vient de lire et on a rien lu donc on doit return null
	sinon on est a la fin du fichier donc on dois afficher line et verifier stat que c'est pas vide*/
	if (line == NULL)
	{
		stat[0] = '\0';
		return (NULL);
	}
	else
	{
		if (find_n(line) == -1)
			return (line);
		else
		{
			stat[0] = 0;
			line[find_n(line)] = '\0';
			return (line);
		}
	}
	return (line);
}

char	*read_me_please(int fd, char *buff, char *line, char *stat)
{
	int	ret;

	ret = 42;
	while (ret > 0 && find_n(line) == -1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		line = ft_strjoin(line, buff);
	}
	if (ret == 0 && ft_strlen(stat) != 0)
		line = ft_last_line(line, stat);
	else if (find_n(line) != -1)
		line = first_call(line, stat);
	else if (ft_strlen(line) == 0)
		line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		stat[BUFFER_SIZE];
	char			*line;

	if (read(fd, buff, 0) == -1 || BUFFER_SIZE < 1 )
		return (NULL);
	line = ft_strdup("");
	if (stat[0])
	{
		if (find_n(stat) != -1)
		{
			line = stat_with_n(line, stat);
			return (line);
		}
		line = ft_strjoin(line, stat);
		stat[0] = '\0';
	}
	line = read_me_please(fd, buff, line, stat);
	return (line);
}
