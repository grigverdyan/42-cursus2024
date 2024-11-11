/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_results.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:48:24 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 21:40:54 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_matrix(int **grid, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n + 2)
	{
		j = -1;
		while (++j < n + 2)
		{
			ft_putchar(grid[i][j] + '0');
			if (j != n + 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	print_evaluation_matrix(int **grid, int n)
{
	int	i;
	int	j;

	i = 0;
	while (++i < n + 1)
	{
		j = 0;
		while (++j < n + 1)
		{
			ft_putchar(grid[i][j] + '0');
			if (j != n)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	print_arr(int	*arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		ft_putchar(arr[i] + '0');
		ft_putchar(' ');
	}
}
