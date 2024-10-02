/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:34 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:35 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	default_parsing(t_table *cmd_table, t_tok_list *tokens_list)
{
	int			idx;
	t_tok_node	*temp;

	idx = -1;
	temp = tokens_list->head;
	while ((++idx < tokens_list->count) && temp->next)
		temp = temp->next;
	if (single_cmd_parse(tokens_list->head, temp))
		return (1);
	add_element(cmd_table, new_cmd_element(new_cmd(tokens_list->head, temp)));
	cmd_table->execution_mode = SINGLE;
	return (0);
}
