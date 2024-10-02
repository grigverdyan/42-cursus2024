/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:32 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:11:34 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_table(t_table *cmd_table)
{
	int			idx;
	t_element	*el;
	int			param;

	idx = -1;
	el = cmd_table->head;
	while (++idx < cmd_table->count)
	{
		if (el->type == COMMAND)
		{
			printf("\nCOMMAND\ncommand: %s\n", el->command->command);
			param = -1;
			while (el->command->params[++param])
				printf("param[%d]: %s\n", param, el->command->params[param]);
			printf("inp: %d\nout: %d\n", el->command->in, el->command->out);
			printf("error: %d\n", el->command->error);
			printf("heredoc: %d\n", el->command->with_hd);
			param = -1;
			while (el->command->hd_word[++param])
				printf("del[%d]: %s\n\n", param, el->command->hd_word[param]);
		}
		else if (el->type == _DELIMITER)
			printf("\nDELIMITER\ndelimiter: %d\n", el->delimiter);
		el = el->next;
	}
}

void	print_tok_list(t_tok_list *tokens_list)
{
	int			idx;
	t_tok_node	*temp;

	idx = -1;
	temp = tokens_list->head;
	while (++idx < tokens_list->count)
	{
		printf("%d: %s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
