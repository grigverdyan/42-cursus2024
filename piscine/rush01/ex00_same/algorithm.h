/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:57:35 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 20:49:22 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

typedef struct s_pos
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_pos;

typedef struct s_lines
{
	int	*line_x;
	int	*line_y;
}	t_lines;

int		run_backtracking(int **grid, int n, int *row, int *col);
int		is_correct_grid(int **grid, int n, int row, int col);
int		check_lines(t_lines *l, t_pos pos, int num, int n);
int		check_line(int *line, int view, int num, int n);
int		check_line2(int *line, int view, int n);
int		dealloc_lines(t_lines *l, int ret_type);
void	change_position(int	*row, int *col, int n, int when);

#endif
