/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:11:57 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 20:57:34 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithm.h"
#include "utils.h"

int	run_backtracking(int **grid, int n, int *row, int *col)
{
	int	num;

	num = 0;
	while (++num <= n)
	{
		if (*row == n + 1)
			return (is_correct_grid(grid, n, n, n));
		grid[*row][*col] = num;
		if (is_correct_grid(grid, n, *row, *col))
		{
			change_position(row, col, n, 1);
			if (run_backtracking(grid, n, row, col))
				return (1);
			change_position(row, col, n, 0);
		}
		grid[*row][*col] = 0;
	}
	return (0);
}

int	is_correct_grid(int **grid, int n, int row, int col)
{
	int		i;
	int		j;
	int		k;
	t_pos	pos;
	t_lines	l;

	l.line_x = (int *)malloc(n * sizeof(int));
	l.line_y = (int *)malloc(n * sizeof(int));
	if (!l.line_x || !l.line_y)
		return (!ft_exit("Allocation ERROR\n"));
	i = 0;
	j = 1;
	k = 1;
	while (j <= n)
	{
		l.line_x[i] = grid[row][j++];
		l.line_y[i] = grid[k++][col];
		++i;
	}
	pos.up = grid[0][col];
	pos.down = grid[n + 1][col];
	pos.left = grid[row][0];
	pos.right = grid[row][n + 1];
	return (check_lines(&l, pos, grid[row][col], n));
}

int	check_lines(t_lines *l, t_pos pos, int num, int n)
{
	int	ret_x;
	int	ret_y;

	ret_x = check_line(l->line_x, pos.left, num, n);
	ret_y = check_line(l->line_y, pos.up, num, n);
	if (ret_x == 2 && ret_y == 2)
		return (dealloc_lines(l, 1));
	if (ret_x == 0 || ret_y == 0)
		return (dealloc_lines(l, 0));
	arr_inplace_rev(l->line_x, n);
	arr_inplace_rev(l->line_y, n);
	ret_x = check_line(l->line_x, pos.right, num, n);
	ret_y = check_line(l->line_y, pos.down, num, n);
	if (ret_x == 0 || ret_y == 0)
		return (dealloc_lines(l, 0));
	return (dealloc_lines(l, 1));
}

int	check_line(int *line, int view, int num, int n)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < n)
	{
		if (line[i] == num)
			++count;
		if (count > 1)
			return (0);
	}
	i = -1;
	while (++i < n)
	{
		if (line[i] == 0)
			return (2);
	}
	return (check_line2(line, view, n));
}

int	check_line2(int *line, int view, int n)
{
	int	i;
	int	max;
	int	count;

	max = line[0];
	i = 1;
	count = 1;
	while (i < n)
	{
		if (line[i] > max)
		{
			max = line[i];
			++count;
		}
		++i;
	}
	if (count == view)
		return (1);
	return (0);
}
