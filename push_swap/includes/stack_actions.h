/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:27 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:54:29 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ACTIONS_H
# define STACK_ACTIONS_H

# include "push_swap.h"

void	swap_stack(t_stack *stack, char *action);
void	rotate_stack(t_stack *stack, char *action);
void	reverse_rotate_stack(t_stack *stack, char *action);
void	push_stack(t_stack *from, t_stack *to, char *action);
void	push_stack_2(t_stack *from, char *action);

#endif	/* STACK_ACTIONS_H */
