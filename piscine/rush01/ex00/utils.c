/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:41:38 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 03:04:19 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	arr_inplace_rev(int *arr, int size)
{
	int	i;
	int	t;

	i = 0;
	while (i < size / 2)
	{
		t = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = t;
		++i;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	ft_exit(char *s)
{
	write(1, s, ft_strlen(s));
	return (1);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	free_grid(int **grid, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		free(grid[i]);
	}
	free(grid);
}
