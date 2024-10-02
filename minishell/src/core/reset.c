/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:29:46 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:29:48 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_data(void)
{
	g_data->command_table = NULL;
	g_data->connection_type = AND_OR;
	g_data->open_par_count = 0;
	g_data->pipe_logic_mode = SINGLE;
	g_data->wildcard_result = 0;
	g_data->wildcard_ends_slash = 0;
	g_data->ctrl_c_pressed = 0;
	if (g_data->envir)
		free_array(g_data->envir);
	g_data->envir = get_envir();
}

void	unlink_open_heredoc_files(void)
{
	DIR			*directory;
	t_dirent	*dir_format;
	char		*s;
	char		*t;

	if (!g_data->temp_dir)
		return ;
	directory = opendir(g_data->temp_dir);
	if (!directory)
		return ;
	dir_format = readdir(directory);
	while (dir_format)
	{
		if (starts_with_string(dir_format->d_name, ".heredoc"))
		{
			s = ft_strjoin(g_data->temp_dir, "/");
			t = ft_strjoin(s, dir_format->d_name);
			unlink(t);
			free(s);
			free(t);
		}
		dir_format = readdir(directory);
	}
	if (directory)
		closedir(directory);
}

void	close_open_fds(void)
{
	t_element	*current;

	if (!g_data->command_table)
		return ;
	current = g_data->command_table->head;
	while (current)
	{
		if (current->type == COMMAND)
		{
			if (current->command->in != -1 && current->command->in != 0)
				close(current->command->in);
			if (current->command->out != 1)
				close(current->command->out);
		}
		current = current->next;
	}
}

void	free_command_table(void)
{
	int			idx;
	t_element	*el;
	t_element	*temp;

	idx = -1;
	el = g_data->command_table->head;
	while (++idx < g_data->command_table->count)
	{
		if (el->type == COMMAND)
		{
			free(el->command->command);
			free_array(el->command->params);
			free_array(el->command->hd_word);
		}
		temp = el;
		free(el->command);
		el = el->next;
		free(temp);
	}
	free(g_data->command_table);
}

void	reset_after_execution(void)
{
	unlink_open_heredoc_files();
	close_open_fds();
	if (g_data->command_table)
		free_command_table();
}
