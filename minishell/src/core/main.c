/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:29:02 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 22:11:54 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*g_data;

void	error_message(char *text, bool is_errno)
{
	if (is_errno)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_table			*cmd_table;

	(void)argv;
	if (argc != 1)
		error_message("Minishell takes no argument! \n", false);
	g_data = data_init(envp);
	init_builtins();
	signal_handler();
	while (true)
	{
		reset_data();
		input = readline("\033[32m Minishell-$ \033[0m");
		cmd_table = parsing(tokenizer(preprocessing(input)));
		if (cmd_table)
			g_data->last_status = execute_command_table(cmd_table);
		reset_after_execution();
		free(input);
	}
	return (0);
}
