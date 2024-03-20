/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:56:19 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:56:21 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "butterfly.h"
#include "stack_actions.h"
#include "sortings.h"

void	butterfly_algo(t_stack *st_a, t_stack *st_b, int size)
{
	int	chunk;

	chunk = generate_chunk(size);
	make_butterfly(st_a, st_b, chunk);
	sort_stack(st_a, st_b);
}

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

void	make_butterfly(t_stack *st_a, t_stack *st_b, int chunk)
{
	int		counter;
	t_lst	*lst;

	counter = 0;
	lst = st_a->head;
	while (st_a->head != NULL)
	{
		if (lst->index <= counter)
		{
			push_stack(st_a, st_b, "pb");
			rotate_stack(st_b, "rb");
			++counter;
		}
		else if (lst->index <= counter + chunk)
		{
			push_stack(st_a, st_b, "pb");
			++counter;
		}
		else
			rotate_stack(st_a, "ra");
		lst = st_a->head;
	}
}

void	sort_stack(t_stack *st_a, t_stack *st_b)
{
	t_lst	*lst;

	while (st_b->head != NULL)
	{
		lst = st_b->head;
		find_max_and_push_a(lst, st_b, st_b->nodes);
		push_stack(st_b, st_a, "pa");
	}
}
