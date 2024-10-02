/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:42 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:44 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_table	*parsing(t_tok_list *tokens_list)
{
	int		error_check;
	t_table	*cmd_table;

	if (!tokens_list)
		return (NULL);
	error_check = 0;
	cmd_table = init_cmd_table();
	if (g_data->pipe_logic_mode == _LOGIC)
		error_check = logic_parsing(cmd_table, tokens_list);
	else if (g_data->pipe_logic_mode == _PIPE)
		error_check = pipe_parsing(cmd_table, tokens_list);
	else
		error_check = default_parsing(cmd_table, tokens_list);
	if (error_check)
	{
		free_tok_list(tokens_list);
		return (NULL);
	}
	g_data->command_table = cmd_table;
	free_tok_list(tokens_list);
	return (cmd_table);
}
