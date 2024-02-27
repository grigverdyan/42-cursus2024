/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:35:26 by grverdya          #+#    #+#             */
/*   Updated: 2024/02/25 16:41:39 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX - 1
		|| read(fd, 0, 0) < 0)
		return (NULL);
	str[fd] = get_read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	next_line = get_return_line(str[fd]);
	str[fd] = update_string(str[fd]);
	return (next_line);
}

char	*get_read_line(int fd, char *str)
{
	char	*temp;
	int		read_len;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	read_len = 1;
	while (read_len != 0 && !ft_strchr(str, '\n'))
	{
		read_len = read(fd, temp, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_len] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_return_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_string(char *str)
{
	size_t	i;
	size_t	j;
	char	*updated_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	updated_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!updated_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		updated_str[j++] = str[i++];
	updated_str[j] = '\0';
	free(str);
	return (updated_str);
}
