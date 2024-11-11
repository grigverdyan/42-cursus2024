/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:25:07 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 20:12:40 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "validation.h"

int	not_greater_than_n(int *sides, int n)
{
	int	i;

	i = -1;
	while (++i < 4 * n)
	{
		if (sides[i] > n)
			return (0);
	}
	return (1);
}

int	is_valid_str(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if ((s[i] > '0' && s[i] <= '9') || is_space(s[i]))
			continue ;
		if (s[i] <= '0' || s[i] > '9' || !is_space(s[i]))
			return (0);
	}
	return (1);
}

int	side_len(int count)
{
	if (count % 4 == 0)
		return (4);
	else if (count % 5 == 0)
		return (5);
	else if (count % 6 == 0)
		return (6);
	else if (count % 7 == 0)
		return (7);
	else if (count % 8 == 0)
		return (8);
	else
		return (9);
}

int	*map_size(char *str, int *n)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (!is_space(str[i]))
		{
			if (str[i + 1] && !is_space(str[i + 1]))
				return (NULL);
			++count;
		}
	}
	if (!(count >= 16 && count <= 36 && count % 4 == 0))
		return (NULL);
	return (fill_sides(str, count, n));
}

int	*fill_sides(char *str, int count, int *n)
{
	int	i;
	int	j;
	int	*arr_sides;

	arr_sides = (int *)malloc(count * sizeof(int));
	if (!arr_sides)
		return (NULL);
	*n = count / 4;
	i = -1;
	j = 0;
	while (j < count)
	{
		if (str[++i] >= '1' && str[i] <= '9')
			arr_sides[j++] = str[i] - '0';
	}
	return (arr_sides);
}
