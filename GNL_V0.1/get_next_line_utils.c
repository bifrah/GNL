/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:29:02 by bifrah            #+#    #+#             */
/*   Updated: 2021/08/12 15:53:25 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_n(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;
	char	c_c;
	int		i;

	c_s = (char *)s;
	c_c = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	if (c_c == '\0')
	{
		while (c_s[i] != c_c)
			i++;
		if (c_s[i] == '\0')
			return (c_s + i);
	}
	while (c_s[i])
	{
		if (c_s[i] == c_c)
			return (c_s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
