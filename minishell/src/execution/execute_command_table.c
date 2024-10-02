/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:36:27 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:36:45 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	on_parent(int *status, int pid)
{
	ignore_signal_handler();
	while (wait(status) != pid)
		;
	if (WTERMSIG(*status) && *status == 2)
		printf("\b\b\b\b\b\b\b\b\b\b\b^C\n");
	else if (*status == 3)
		printf("^\\Quit: 3\n");
	signal_handler();
}

int	execute_execve_command(t_command *command, t_string	command_path)
{
	t_string	*params_with_command;
	int			pid;
	int			status;

	status = 0;
	params_with_command = get_full_param(command->command, command->params);
	pid = fork();
	if (pid == 0)
	{
		handle_redirections(command);
		default_signal_handler();
		if (execve(command_path, params_with_command,
				g_data->envir) == -1)
			return (errno);
	}
	else
		on_parent(&status, pid);
	guard_free(command_path);
	free_array(params_with_command);
	if (status != 0)
		return (1);
	return (0);
}

int	prepare_and_execute_execve_command(t_command *command)
{
	t_string	command_path;

	if (access(command->command, X_OK) == 0)
		command_path = ft_strdup(command->command);
	else
		command_path = get_command_path(command->command);
	if (!command_path)
	{
		if (starts_with_string(command->command, "/")
			|| !find_node_with_key(g_data->env_list, "PATH"))
			print_error_message(command->command, NO_SUCH_FILE_OR_DIR);
		else
			print_error_message(command->command, COMMAND_NOT_FOUND);
		return (127);
	}
	return (execute_execve_command(command, command_path));
}

int	execute_command(t_command *command, char mode)
{
	t_func	function;
	int		status;
	int		std_out;
	int		std_in;

	if (command->in == -1)
	{
		ft_putstr_fd("minishell: Input File: No such file or directory\n", 2);
		return (1);
	}
	if (!command->command)
		return (0);
	if (mode == BUILTIN)
	{
		std_out = dup(STDOUT_FILENO);
		std_in = dup(STDIN_FILENO);
		handle_redirections(command);
		function = get_function_with_name(command->command);
		status = function(command->params);
		dup2(std_out, 1);
		dup2(std_in, 0);
		return (status);
	}
	return (prepare_and_execute_execve_command(command));
}

int	execute_command_table(t_table *table)
{
	t_element	*current_element;

	handle_heredocs(table);
	if (table->execution_mode == SINGLE)
		return (execute_command(table->head->command,
				find_execution_mode(table->head->command)));
	if (table->execution_mode == _PIPE)
		return (execute_with_pipe(table));
	current_element = table->head;
	while (current_element)
	{
		if (current_element->type == _DELIMITER)
			handle_delimiter(&current_element);
		else if (can_execute_next_command())
			table->status = execute_command(current_element->command,
					find_execution_mode(current_element->command));
		current_element = current_element->next;
	}
	return (table->status);
}
