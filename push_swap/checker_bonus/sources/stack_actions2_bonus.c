/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:51:58 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:51:59 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_actions_bonus.h"
#include "utils_bonus.h"

void	ss_stacks(t_stack *st_a, t_stack *st_b)
{
	swap_stack(st_a);
	swap_stack(st_b);
}

void	rr_stacks(t_stack *st_a, t_stack *st_b)
{
	rotate_stack(st_a);
	rotate_stack(st_b);
}

void	rrr_stacks(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate_stack(st_a);
	reverse_rotate_stack(st_b);
}
