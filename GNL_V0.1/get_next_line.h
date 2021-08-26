/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:28:52 by bifrah            #+#    #+#             */
/*   Updated: 2021/08/12 11:11:20 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 40

char				*get_next_line(int fd);
char	            *read_me_please(int fd, char *buff);
unsigned int		ft_strlen(const char *str);
int                 find_n(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strdup(const char *src);
char				*stat_with_n(char **stat);

#endif
