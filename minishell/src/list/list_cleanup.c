/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:41:09 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:41:11 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_node(t_node *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

static void	remove_last(t_list *list)
{
	t_node	*last;

	if (list->count == 0)
		return ;
	last = list->tail;
	if (list->count == 1)
	{
		list->tail = NULL;
		list->head = NULL;
	}
	else
		list->tail = last->prev;
	free_node(last);
	list->count--;
}

void	free_list(t_list *list)
{
	while (list->count > 0)
		remove_last(list);
	free(list);
}
