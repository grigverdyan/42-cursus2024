/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:29:15 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:29:16 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*get_command_with_index(int index)
{
	t_element	*current;
	int			i;

	i = -1;
	current = g_data->command_table->head;
	while (++i < index)
		current = current->next;
	return (current->command);
}

int	command_child(int index)
{
	t_command	*command;
	int			status;

	if (dup2(g_data->fds[index - 1][0], STDIN_FILENO) == -1)
		free_and_exit(1);
	if (dup2(g_data->fds[index][1], STDOUT_FILENO) == -1)
		free_and_exit(1);
	close_fds(g_data->fds, g_data->command_table->count + 1);
	command = get_command_with_index(index - 1);
	status = execute_command(command, find_execution_mode(command));
	free_and_exit(status);
	return (1);
}

static int	wait_for_end(int pid, int *status)
{
	waitpid(pid, status, 0);
	while (wait(NULL) != -1 || errno != ECHILD)
		;
	if (*status > 0)
		return (1);
	return (0);
}

int	execute_children(t_table *table)
{
	int			i;
	int			pid;
	int			status;
	t_element	*current;

	i = 0;
	current = table->head;
	while (++i <= table->count)
	{
		if (current->command->in == -1)
			status = print_error_message("Input File", NO_SUCH_FILE_OR_DIR);
		else
		{
			pid = fork();
			if (pid == -1)
				return (print_error_message("fork", RSRC_TEMP_UNAVAILABLE));
			if (pid == 0)
				command_child(i);
		}
		current = current->next;
	}
	close_fds(g_data->fds, table->count + 1);
	return (wait_for_end(pid, &status));
}

int	execute_with_pipe(t_table *table)
{
	int			i;

	g_data->fds = malloc(sizeof(int *) * (table->count + 1));
	i = -1;
	while (++i < table->count + 1)
		g_data->fds[i] = (int *)malloc(sizeof(int) * 2);
	i = -1;
	while (++i < table->count + 1)
		pipe(g_data->fds[i]);
	if (table->head->command->in != -1)
		dup2(table->head->command->in, g_data->fds[0][0]);
	dup2(table->tail->command->out, g_data->fds[table->count][1]);
	return (execute_children(table));
}
