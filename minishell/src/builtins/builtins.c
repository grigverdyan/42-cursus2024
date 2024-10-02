/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:25:56 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:25:58 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_echo_option(t_string	option)
{
	int	i;

	i = 1;
	if (option[0] != '-' || option[1] != 'n')
		return (FALSE);
	while (option[++i])
		if (option[i] != 'n')
			return (FALSE);
	return (TRUE);
}

int	echo(char **str)
{
	int	i;
	int	has_option;

	i = -1;
	if (str[0])
		has_option = is_echo_option(str[0]);
	while (str[++i] && is_echo_option(str[i]))
		;
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!has_option)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	env(char **args)
{
	(void) args;
	for_each(g_data->env_list, print_env_node);
	return (0);
}

int	pwd(char **args)
{
	(void) args;
	ft_putstr_fd(g_data->pwd, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
