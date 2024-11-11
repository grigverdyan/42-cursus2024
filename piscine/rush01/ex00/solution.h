/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:21:19 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 20:12:22 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

void	solver(int *arr, int n);
int		**alloc_matrix(int n);
void	fill_grid(int *sides, int **grid, int n);
void	fill_with_0(int **grid, int n);

#endif
