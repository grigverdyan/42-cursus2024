/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:10 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:26:12 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_with_name(t_string name)
{
	int	i;

	i = -1;
	while (++i < BUILTINS_COUNT)
	{
		if (!ft_strcmp(g_data->builtins[i].name, name))
			return (TRUE);
	}
	return (FALSE);
}

t_func	get_function_with_name(t_string name)
{
	int	i;

	i = -1;
	while (++i < BUILTINS_COUNT)
		if (!ft_strcmp(g_data->builtins[i].name, name))
			return (g_data->builtins[i].function);
	return (NULL);
}

int	is_valid_export_key(char *key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	while (key[++i])
	{
		if (contains("!@#$%^&*()-+[]\\|{};:.><,/?.=", key[i]))
			return (0);
	}
	return (1);
}

void	not_valid_identifier(t_string command, t_string identifier)
{
	t_string	error_message;
	t_string	temp;
	t_string	temp1;

	temp1 = ft_strjoin(command, ": `");
	temp = ft_strjoin(temp1, identifier);
	error_message = ft_strjoin(temp, "'");
	print_error_message(error_message, NOT_VALID_IDENTIFIER);
	free(temp);
	free(temp1);
	free(error_message);
}
