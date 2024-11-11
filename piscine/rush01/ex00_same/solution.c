/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:35:26 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 21:32:47 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "algorithm.h"
#include "solution.h"

void	solver(int *arr_sides, int n)
{
	int	**grid;
	int	row;
	int	col;

	grid = alloc_matrix(n);
	fill_grid(arr_sides, grid, n);
	free(arr_sides);
	row = 1;
	col = 1;
	if (!run_backtracking(grid, n, &row, &col))
	{
		ft_exit("Error: No Solution\n");
		return ;
	}
	print_evaluation_matrix(grid, n);
	free_grid(grid, n);
}

int	**alloc_matrix(int n)
{
	int	i;
	int	**grid;

	grid = (int **)malloc(sizeof(int *) * (n + 2));
	if (!grid)
		write (1, "Error\n", 6);
	i = -1;
	while (++i < n + 2)
	{
		grid[i] = (int *)malloc(sizeof(int) * (n + 2));
		if (!grid[i])
		{
			while (i >= 0)
				free(grid[i--]);
			free(grid);
			ft_exit("Allocation Error\n");
		}
	}
	return (grid);
}

void	fill_with_0(int **grid, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n + 2)
	{
		j = -1;
		while (++j < n + 2)
			grid[i][j] = 0;
	}
}

void	fill_grid(int *sides, int **grid, int n)
{
	int	i;
	int	k;

	fill_with_0(grid, n);
	i = 0;
	k = 0;
	while (++i < n + 1)
		grid[0][i] = sides[k++];
	i = 0;
	while (++i < n + 1)
		grid[n + 1][i] = sides[k++];
	i = 0;
	while (++i < n + 1)
		grid[i][0] = sides[k++];
	i = 0;
	while (++i < n + 1)
		grid[i][n + 1] = sides[k++];
}
