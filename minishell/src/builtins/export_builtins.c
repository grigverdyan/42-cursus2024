/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:44 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:26:46 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_node(char *key, char *value, char has_eqaul)
{
	t_node	*node;

	node = find_node_with_key(g_data->env_list, key);
	if (node && has_eqaul)
		update_with_key(g_data->env_list, key, value);
	else if (!node)
	{
		if (has_eqaul)
			node = new_node(key, value);
		else
			node = new_node(key, NULL);
		add(g_data->env_list, node);
	}
}

void	for_each_export(char *argument, int len)
{
	int		i;
	char	has_equal;

	i = -1;
	has_equal = 0;
	while (++i < len && argument[i] != 0)
		;
	if (argument[i] == 0 && i < len)
	{
		has_equal = 1;
		i++;
	}
	export_node(argument, argument + i, has_equal);
}

int	is_valid_env_var(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '=')
		;
	if (str[i] == '=')
	{
		str[i++] = 0;
	}
	return (is_valid_export_key(str));
}

int	export(char **arguments)
{
	int	i;
	int	status;
	int	len;

	i = -1;
	status = 0;
	if (!arguments || !arguments[0])
	{
		export_print(g_data->env_list);
		return (0);
	}
	while (arguments[++i])
	{
		len = ft_strlen(arguments[i]);
		if (is_valid_env_var(arguments[i]))
			for_each_export(arguments[i], len);
		else
		{
			not_valid_identifier("export", arguments[i]);
			status = 1;
		}
	}
	return (status);
}
