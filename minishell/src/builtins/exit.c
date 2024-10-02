/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:36 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:26:38 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_and_exit(t_string to_free)
{
	t_string	error_message;

	error_message = ft_strjoin("exit: ", to_free);
	free(to_free);
	print_error_message(error_message, NUMERIC_ARGUMENT_REQUIRED);
	free_and_exit (255);
}

void	check_for_numeric_argument(t_string trimmed)
{
	int			i;

	i = 0;
	if ((trimmed[0] == '-' && (ft_strlen(trimmed) > 20 || \
		(ft_strlen(trimmed) == 20 \
		&& ft_strcmp(trimmed + 1, "9223372036854775808") > 0)))
		|| (trimmed[0] != '-' && (ft_strlen(trimmed) > 19 || \
		(ft_strlen(trimmed) == 19 \
		&& ft_strcmp(trimmed, "9223372036854775807") > 0))))
		print_error_and_exit(trimmed);
	while (trimmed[++i])
		if (!ft_isdigit(trimmed[i]))
			print_error_and_exit(trimmed);
}

int	builtin_exit(char **args)
{
	long long int		exit_status;
	int					len;
	char				*trimmed;

	ft_putstr_fd("exit\n", 1);
	if (!args || !args[0])
		free_and_exit(0);
	exit_status = 0;
	trimmed = ft_strtrim(args[0]);
	if (!trimmed)
		print_error_and_exit(args[0]);
	check_for_numeric_argument(trimmed);
	len = text_len(args);
	if (len > 1)
	{
		free(trimmed);
		return (print_error_message("exit", TOO_MANY_ARGUMENTS));
	}
	exit_status = basic_atoi(trimmed);
	free(trimmed);
	free_and_exit(exit_status % 256);
	return (0);
}
