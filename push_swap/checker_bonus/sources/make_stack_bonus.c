/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:51:09 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:51:15 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_stack_bonus.h"
#include "cleanup_bonus.h"
#include "utils_bonus.h"

void	init_stacks(t_stack *st_a, t_stack *st_b)
{
	st_a->head = NULL;
	st_a->tail = NULL;
	st_a->nodes = 0;
	st_b->head = NULL;
	st_b->tail = NULL;
	st_b->nodes = 0;
}

void	make_stack_a(t_stack *stack, int *unordered, int size)
{
	int	i;

	stack->head = NULL;
	stack->tail = NULL;
	stack->head = make_lst(stack, unordered, 0);
	i = 0;
	while (++i < size)
		make_lst(stack, unordered, i);
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->nodes = size;
}

t_lst	*make_lst(t_stack *stack, int *unordered, int i)
{
	t_lst	*new_lst;
	t_lst	*temp_head;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		free_list_and_exit(stack, unordered, i);
	if (i == 0)
	{
		new_lst->value = unordered[0];
		new_lst->prev = NULL;
	}
	else
	{
		temp_head = stack->head;
		while (temp_head->next != NULL)
			temp_head = temp_head->next;
		new_lst->value = unordered[i];
		temp_head->next = new_lst;
		new_lst->prev = temp_head;
	}
	stack->tail = new_lst;
	new_lst->next = NULL;
	return (new_lst);
}
