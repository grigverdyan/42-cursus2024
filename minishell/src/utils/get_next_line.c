/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:04 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:11 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	while (s2 && s2[++j])
		ptr[i++] = s2[j];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = get_buffer(fd, str);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	temp = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	str = temp;
	return (line);
}

char	*get_buffer(int fd, char *str)
{
	char	*temp;
	int		bytes;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0 || (!bytes && !str))
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		if (!str)
			str = ft_strdup(temp);
		else
			str = ft_strjoin_gnl(str, temp);
		if (!str)
			return (NULL);
	}
	free(temp);
	return (str);
}
