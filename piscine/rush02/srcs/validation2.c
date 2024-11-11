/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:00:20 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:36:43 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "allocation.h"

int	get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_exit("File Error\n", -2));
	return (fd);
}

int	check_dict(int fd)
{
	char	*line;
	int		ret;

	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		ret = is_valid_line(line);
		if (ret == 0)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	is_valid_line(char *line)
{
	char	*num;
	char	*num_str;
	int		colon;

	colon = get_before_colon(line);
	if (colon == -1)
		return (0);
	else if (colon == -2)
		return (2);
	num = ft_strndup(line, colon);
	num = ft_atoi_string(num, 0);
	if (!num || ft_strlen(num) > 37)
		return (free_arr(num, 0));
	if (!ft_strlen(num) && colon > 0)
		return (free_arr(num, 0));
	num_str = get_num_str(line, colon);
	if ((!ft_strlen(num) && !num_str) || !is_valid_num(num))
		return (free_arrs(num, num_str, 2));
	if (num && !num_str)
		return (free_arrs(num, num_str, 0));
	return (free_arrs(num, num_str, 1));
}

int	get_before_colon(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	if (str[i] == '\0')
		return (-2);
	i = 0;
	while (str[i] && str[i] != ':')
		++i;
	if (str[i] != ':')
		return (-1);
	return (i);
}

char	*get_num_str(char *line, int i)
{
	char	*num_str;
	int		j;
	int		len;

	len = ft_strlen(line);
	++i;
	while (line[i] && is_space(line[i]))
		++i;
	rtrim_space(line, &len);
	num_str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!num_str)
		return (0);
	j = 0;
	while (line[i])
	{
		num_str[j] = line[i];
		++j;
		++i;
	}
	num_str[j] = '\0';
	return (num_str);
}
