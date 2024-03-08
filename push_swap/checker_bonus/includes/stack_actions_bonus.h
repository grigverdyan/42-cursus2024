/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:26:31 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:26:32 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ACTIONS_BONUS_H
# define STACK_ACTIONS_BONUS_H

# include "push_swap_bonus.h"

void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	push_stack(t_stack *from, t_stack *to);
void	push_stack_2(t_stack *from);
void	ss_stacks(t_stack *st_a, t_stack *st_b);
void	rr_stacks(t_stack *st_a, t_stack *st_b);
void	rrr_stacks(t_stack *st_a, t_stack *st_b);

#endif	/* STACK_ACTIONS_BONUS_H */
