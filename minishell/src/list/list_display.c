/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:41:20 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:41:22 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_node(t_node *node)
{
	if (node->value)
	{
		if (node->value[0])
			printf("%s=%s\n", node->key, node->value);
		else
			printf("%s=\n", node->key);
	}
}

void	export_print(t_list *list)
{
	int		i;
	t_node	*min_node;
	t_node	*current;

	i = -1;
	for_each(list, unset_index);
	while (++i < list->count)
	{
		current = list->head;
		while (current && current->index != -1)
			current = current->next;
		min_node = current;
		current = current->next;
		while (current)
		{
			if (current->index == -1
				&& ft_strcmp(current->key, min_node->key) < 0)
				min_node = current;
			current = current->next;
		}
		min_node->index = i;
		print_export_node(min_node);
	}
}

void	print_export_node(t_node *node)
{
	printf("declare -x ");
	if (!node->value)
		printf("%s\n", node->key);
	else if (!node->value[0])
		printf("%s=\"\"\n", node->key);
	else
		printf("%s=\"%s\"\n", node->key, node->value);
}

void	print_list(t_list *list)
{
	for_each(list, &print_env_node);
}
