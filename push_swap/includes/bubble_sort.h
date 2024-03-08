/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:22:48 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:24:17 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUBBLE_SORT_H
# define BUBBLE_SORT_H

# include "ft_printf.h"
# include "push_swap.h"

void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
void	print_array(int *arr, int size);
int		*copy_into_sorted(int *arr, int size);
int		*get_nums(int nums_count, char **argv);

#endif   /* BUBBLE_SORT_H */
