/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:40 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:42 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok_node	*iterate_and_add_next(t_tok_node	*node, t_table *cmd_table)
{
	while (node->next && (node->next->key == AND_OR || node->next->key == OR_IF
			|| node->next->key == L_BRACE || node->next->key == R_BRACE))
	{
		add_element(cmd_table, new_element(node->next->key));
		node = node->next;
	}
	return (node);
}

t_tok_node	*iterate_and_add(t_tok_node	*node, t_table *cmd_table)
{
	while (node->next && (node->key == AND_OR || node->key == OR_IF
			|| node->key == L_BRACE || node->key == R_BRACE))
	{
		add_element(cmd_table, new_element(node->key));
		node = node->next;
	}
	return (node);
}

t_tok_node	*iterate(t_tok_node	*to, char if_true)
{
	while (to->next)
	{
		if ((if_true && (to->next->key == AND_OR || to->next->key == OR_IF
					|| to->next->key == L_BRACE || to->next->key == R_BRACE))
			|| (!if_true && !(to->next->key == AND_OR || to->next->key == OR_IF
					|| to->next->key == L_BRACE || to->next->key == R_BRACE)))
			break ;
		to = to->next;
	}
	return (to);
}

int	logic_parsing(t_table *cmd_table, t_tok_list *tokens_list)
{
	t_tok_node	*to;
	t_tok_node	*from;

	from = tokens_list->head;
	from = iterate_and_add(from, cmd_table);
	to = from;
	while (from != NULL)
	{
		to = iterate(to, 1);
		if (single_cmd_parse(from, to))
			return (1);
		add_element(cmd_table, new_cmd_element(new_cmd(from, to)));
		if (to->next == NULL)
			break ;
		from = to;
		to = iterate(to, 0);
		from = iterate_and_add_next(from, cmd_table);
		if (from && (from->key == AND_OR || from->key == OR_IF
				|| from->key == L_BRACE || from->key == R_BRACE))
			from = from->next;
	}
	cmd_table->execution_mode = _LOGIC;
	return (0);
}
