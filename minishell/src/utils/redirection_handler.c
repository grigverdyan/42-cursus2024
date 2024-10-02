/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:24 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:26 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirections(t_command *command)
{
	dup2(command->out, 1);
	dup2(command->in, 0);
}

void	reset_redirections(t_command *command)
{
	dup2(1, command->out);
	dup2(0, command->in);
}

void	handle_heredocs(t_table *table)
{
	t_element	*current;
	int			index;

	index = 0;
	current = table->head;
	while (current)
	{
		if (current->type == COMMAND && current->command->with_hd)
			feel_input_file(current->command, index);
		index++;
		current = current->next;
	}
}
