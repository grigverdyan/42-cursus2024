/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:24 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:54:26 by grverdya         ###   ########.fr       */
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

#endif   /* SORTINGS_H */
