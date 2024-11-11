/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:43:46 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 21:32:37 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_exit(char *s);
int		ft_strlen(char *s);
void	ft_putchar(char c);
void	print_evaluation_matrix(int **grid, int n);
void	print_matrix(int **grid, int n);
void	print_arr(int *arr, int n);
void	fill_grid_with_default(int *sides, int **grid, int n);
int		is_space(char c);
void	free_grid(int **grid, int n);
void	arr_inplace_rev(int *arr, int size);

#endif
