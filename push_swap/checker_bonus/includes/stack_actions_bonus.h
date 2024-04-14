/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:38:29 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:38:32 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ACTIONS_BONUS_H
# define STACK_ACTIONS_BONUS_H

# include "checker_bonus.h"

void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	push_stack(t_stack *from, t_stack *to);
void	push_stack_2(t_stack *from);
void	ss_stacks(t_stack *st_a, t_stack *st_b);
void	rr_stacks(t_stack *st_a, t_stack *st_b);
void	rrr_stacks(t_stack *st_a, t_stack *st_b);

#endif	/* STACK_ACTIONS_BONUS_H */
