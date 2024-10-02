/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:12 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:34:56 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_string	get_string_indexed(t_string str, int command_index)
{
	t_string	number_string;
	t_string	temp1;
	t_string	temp2;
	t_string	result;

	number_string = ft_itoa(command_index);
	temp1 = ft_strjoin(g_data->temp_dir, "/");
	temp2 = ft_strjoin(temp1, str);
	free(temp1);
	result = ft_strjoin(temp2, number_string);
	free(number_string);
	free(temp2);
	return (result);
}

void	heredoc_readline(int file_descriptor, int has_quote, t_string cleared)
{
	t_string	ptr;
	t_string	line;

	heredoc_signal_handler();
	while (true)
	{
		line = readline("> ");
		if (!line || g_data->ctrl_c_pressed)
		{
			close(file_descriptor);
			break ;
		}
		if (!has_quote)
		{
			ptr = fill_env(line);
			free(line);
			line = ptr;
		}
		if (!ft_strcmp(line, cleared))
			break ;
		write(file_descriptor, line, ft_strlen(line));
		write(file_descriptor, "\n", 1);
		free(line);
	}
	signal_handler();
}

void	fill_heredoc_file(t_string hd_word, t_string file_name)
{
	t_string	cleared;
	int			has_quote;
	int			file_descriptor;

	cleared = clear_quotes(hd_word);
	has_quote = contains(hd_word, '\'');
	file_descriptor = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0777);
	g_data->ctrl_c_pressed = 0;
	heredoc_readline(file_descriptor, has_quote, cleared);
	free(cleared);
	close(file_descriptor);
}

void	feel_input_file(t_command *command, int command_index)
{
	t_string	file_name;
	int			index;

	index = -1;
	file_name = get_string_indexed(".heredoc", command_index);
	while (command->hd_word[++index])
	{
		fill_heredoc_file(command->hd_word[index], file_name);
		if (!command->hd_word[index + 1] && command->in == 0)
			command->in = open(file_name, O_RDONLY, 0777);
		else
			unlink(file_name);
	}
	free(file_name);
}
