/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:50:19 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:50:23 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX - 1)
		return (NULL);
	str[fd] = get_buffer(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	i = 0;
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\n')
		i++;
	line = ft_substr(str[fd], 0, i);
	temp = ft_substr(str[fd], i, ft_strlen(str[fd]) - i);
	free(str[fd]);
	str[fd] = temp;
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
			str = ft_strjoin(str, temp);
		if (!str)
			return (NULL);
	}
	free(temp);
	return (str);
}
