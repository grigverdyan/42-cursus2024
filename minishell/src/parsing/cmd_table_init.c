/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:30 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:32 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*new_cmd(t_tok_node *from, t_tok_node *to)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->command = fill_command(from, to);
	cmd->params = fill_params(from, to);
	cmd->in = fill_input(from, to);
	cmd->out = fill_output(from, to);
	cmd->error = fill_error(from, to);
	cmd->with_hd = fill_heredoc(from, to);
	cmd->hd_word = fill_delimiter(from, to);
	return (cmd);
}

t_element	*new_cmd_element(t_command *cmd)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	element->command = cmd;
	element->delimiter = NO_TOKEN;
	element->type = COMMAND;
	element->next = NULL;
	element->previous = NULL;
	return (element);
}

t_element	*new_element(int token)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	element->command = NULL;
	element->delimiter = token;
	element->type = _DELIMITER;
	element->next = NULL;
	element->previous = NULL;
	return (element);
}

void	add_element(t_table *cmd_table, t_element *element)
{
	element->previous = cmd_table->tail;
	if (cmd_table->count == 0)
		cmd_table->head = element;
	else
		cmd_table->tail->next = element;
	cmd_table->tail = element;
	cmd_table->count++;
}

t_table	*init_cmd_table(void)
{
	t_table	*cmd_table;

	cmd_table = malloc(sizeof(t_table));
	cmd_table->count = 0;
	cmd_table->execution_mode = SINGLE;
	cmd_table->head = NULL;
	cmd_table->tail = NULL;
	cmd_table->status = 0;
	return (cmd_table);
}
