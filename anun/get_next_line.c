/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:02:57 by grverdya          #+#    #+#             */
/*   Updated: 2024/02/27 21:58:11 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!line)
		return (NULL);
	temp = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	str = temp;
	return (line);
}

char	*get_buffer(int fd, char *str)
{
	char	*temp;
	int		read_len;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	read_len = 1;
	while (read_len > 0 && !ft_strchr(str, '\n'))
	{
		read_len = read(fd, temp, BUFFER_SIZE);
		if (read_len < 0 || (!read_len && !str))
		{
			free(temp);
			return (NULL);
		}
		temp[read_len] = '\0';
		if (!str)
			str = ft_strdup(temp);
		else
			str = ft_strjoin(str, temp);
		if (!str)
			return (NULL);
		temp = NULL;
	}
	free(temp);
	return (str);
}
