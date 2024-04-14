/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:19 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:54:21 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STACK_H
# define MAKE_STACK_H

# include "push_swap.h"

void	make_stack_a(t_stack *stack, int *unordered, int *sorted, int size);
void	init_stack_b(t_stack *st_b, int **sorted);
t_lst	*make_lst(t_stack *stack, int *arrays[], int size, int i);
int		find_index(int *arr, int value, int size);

#endif   /* MAKE_STACK_H */
