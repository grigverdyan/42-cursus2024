/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balanced_parentheses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:12:34 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:12:35 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*push_parentheses(t_node_par **top_ref, int new_data)
{
	t_node_par	*new_node;

	new_node = (t_node_par *)malloc(sizeof(t_node_par));
	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
	return (NULL);
}

int	pop_parentheses(t_node_par **top_ref)
{
	char		res;
	t_node_par	*top;

	top = *top_ref;
	res = top->data;
	*top_ref = top->next;
	free(top);
	return (res);
}

int	is_matching(char chr1, char chr2)
{
	if (chr1 == '(' && chr2 == ')')
		return (1);
	else
		return (0);
}

void	free_par_list(t_node_par *list)
{
	t_node_par	*ptr;

	while (list != NULL)
	{
		ptr = list;
		list = list->next;
		free(ptr);
	}
	free(list);
}

int	is_balanced(char *exp)
{
	int			idx;
	t_node_par	*stack;

	idx = -1;
	stack = NULL;
	while (exp[++idx])
	{
		if (exp[idx] == '(')
			push_parentheses(&stack, exp[idx]);
		if (exp[idx] == ')')
		{
			if (!stack || !is_matching(pop_parentheses(&stack), exp[idx]))
			{
				free_par_list(stack);
				return (0);
			}
		}
	}
	if (!stack)
		return (1);
	free_par_list(stack);
	return (0);
}
