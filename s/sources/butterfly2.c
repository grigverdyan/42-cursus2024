/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:56:21 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:56:23 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "butterfly.h"
#include "stack_actions.h"

void	find_max_and_push_a(t_lst *lst, t_stack *stack_b, int size)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->index == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					reverse_rotate_stack(stack_b, "rrb");
			}
			else
				while (i-- > 0)
					rotate_stack(stack_b, "rb");
			break ;
		}
		++i;
		lst = lst->next;
		if (lst == stack_b->head)
			is_tail = 1;
	}
}

void	find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size)
{
	int	i;
	int	is_tail;

	i = 0;
	is_tail = 0;
	while (is_tail == 0)
	{
		if (lst->index == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					reverse_rotate_stack(stack_a, "rra");
			}
			else
				while (i-- > 0)
					rotate_stack(stack_a, "ra");
			break ;
		}
		++i;
		lst = lst->next;
		if (lst == stack_a->head)
			is_tail = 1;
	}
}
