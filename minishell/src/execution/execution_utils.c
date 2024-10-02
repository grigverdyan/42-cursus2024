/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:36:55 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:37:03 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	find_execution_mode(t_command *command)
{
	if (is_builtin_with_name(command->command))
		return (BUILTIN);
	return (EXECVE);
}

int	can_execute_next_command(void)
{
	if (g_data->connection_type == AND_OR
		&& g_data->command_table->status == 0)
		return (TRUE);
	if (g_data->connection_type == OR_IF
		&& g_data->command_table->status != 0)
		return (TRUE);
	return (FALSE);
}

void	pass_not_executable_quotes(t_element	**current, int *opened_count)
{
	while (*current)
	{
		if ((*current)->delimiter == L_BRACE)
			(*opened_count)++;
		else if ((*current)->delimiter == R_BRACE)
			(*opened_count)--;
		if ((*opened_count) == 0)
			return ;
		(*current) = (*current)->next;
	}
}

void	handle_delimiter(t_element	**current)
{
	int	opened_count;

	opened_count = 0;
	if ((*current)->delimiter == AND_OR || (*current)->delimiter == OR_IF)
	{
		g_data->connection_type = (*current)->delimiter;
		if ((*current)->next->type == _DELIMITER && !can_execute_next_command())
		{
			(*current) = (*current)->next->next;
			opened_count = 1;
			pass_not_executable_quotes(current, &opened_count);
		}
	}
	else if ((*current)->delimiter == L_BRACE)
		opened_count++;
	else if ((*current)->delimiter == R_BRACE)
		opened_count--;
}
