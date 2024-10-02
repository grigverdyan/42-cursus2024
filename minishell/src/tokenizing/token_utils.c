/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:15 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:17 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_tok(t_tok_list *list, t_tok_node *node)
{
	node->prev = list->tail;
	if (list->count == 0)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	list->count++;
}

t_tok_node	*new_tok_node(int key, char *value)
{
	t_tok_node	*node;

	node = malloc(sizeof(t_tok_node));
	node->key = key;
	node->value = ft_strdup(value);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_tok_list	*new_tok_list(void)
{
	t_tok_list	*list;

	list = malloc(sizeof(t_tok_list));
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

static void	remove_last(t_tok_list *list)
{
	t_tok_node	*last;

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
	free(last->value);
	free(last);
	list->count--;
}

void	free_tok_list(t_tok_list *list)
{
	while (list->count > 0)
		remove_last(list);
	free(list);
}
