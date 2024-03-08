/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:23:50 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:24:12 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTINGS_H
# define SORTINGS_H

# include "libft.h"
# include "push_swap.h"

void	double_sort(int *unordered, int *sorted);
void	forbbiden_sorting(int size, t_stack *stack_a, t_stack *stack_b);
void	triple_sort(t_stack *stack_a);
void	fourple_sort(t_stack *stack_a, t_stack *stack_b, int size);
void	fiveple_sort(t_stack *stack_a, t_stack *stack_b, int size);
void	find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size);
void	find_max_and_push_a(t_lst *lst, t_stack *stack_b, int size);
#endif   /* SORTINGS_H */
