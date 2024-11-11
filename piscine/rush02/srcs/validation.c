/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:00:33 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:35:17 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#include "ft_string.h"
#include "get_next_line.h"
#include "print_functions.h"

#include "validation.h"
#include "utils.h"
#include "allocation.h"

int	check_params(char *file, char *number)
{
	int		fd;
	t_line	*dict;
	int		ret;

	number = ft_atoi_string(number, 1);
	if (!number || ft_strlen(number) > 39)
		return (ft_exit("Argument Error\n", 1));
	fd = get_fd(file);
	if (check_dict(fd) == 1)
	{
		close(fd);
		return (ft_exit("Dict Error\n", 1));
	}
	close(fd);
	fd = get_fd(file);
	if (fd < 0)
		return (1);
	dict = get_dict(fd, &ret);
	if (!dict)
		return (ft_exit("Allocation Error\n", 1));
	print_number(number, ft_strlen(number), dict);
	free_dict(dict);
	return (0);
}

t_line	*get_dict(int fd, int *ret)
{
	t_line	*dict;
	char	*line;
	int		i;

	dict = (t_line *)malloc(sizeof(t_line) * NUM_COUNT);
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (is_valid_line(line) == 1)
		{
			*ret = fill_dict(dict, line, ++i);
			if (*ret == 1)
			{
				free(line);
				free(dict);
				return (NULL);
			}
			else if (*ret == 2)
				--i;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (dict);
}

int	fill_dict(t_line *dict, char *line, int i)
{
	int		j;
	char	*num;
	char	*num_str;
	int		colon;

	colon = get_before_colon(line);
	num = ft_strndup(line, colon);
	num = ft_atoi_string(num, 0);
	if (!num || !is_valid_num(num))
		return (free_arr(num, 2));
	num_str = get_num_str(line, colon);
	dict[i].key = (char *)malloc(sizeof(char) * ft_strlen(num + 1));
	dict[i].value = (char *)malloc(sizeof(char) * ft_strlen(num_str + 1));
	if (!dict[i].key || !dict[i].value)
	{	
		j = -1;
		while (++j < i)
		{
			free_arrs(dict[j].key, dict[j].value, 1);
		}
		return (free_arrs(num, num_str, 1));
	}
	ft_strcpy(dict[i].key, num);
	ft_strcpy(dict[i].value, num_str);
	return (free_arrs(num, num_str, 0));
}

int	is_valid_num(char *num)
{
	char	**nums;
	int		i;

	nums = get_default_nums();
	i = -1;
	while (++i < NUM_COUNT)
	{
		if (ft_strcmp(nums[i], num) == 0)
		{
			free_matrix(nums);
			return (1);
		}
	}
	free_matrix(nums);
	return (0);
}
