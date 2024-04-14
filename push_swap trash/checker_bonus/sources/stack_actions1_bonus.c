/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:27:25 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:27:26 by gverdyan         ###   ########.fr       */
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
