/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:44 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:45 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_parsing(t_table *cmd_table, t_tok_list *tokens_list)
{
	t_tok_node	*from;
	t_tok_node	*to;

	from = tokens_list->head;
	to = tokens_list->head;
	while (from != NULL)
	{
		while (to->next && to->next->key != PIPE)
			to = to->next;
		if (single_cmd_parse(from, to))
			return (1);
		add_element(cmd_table, new_cmd_element(new_cmd(from, to)));
		if (to->next == NULL)
			break ;
		from = to->next->next;
		to = from;
	}
	cmd_table->execution_mode = _PIPE;
	return (0);
}
