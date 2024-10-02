/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:28:41 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:28:45 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*init_env_list(char **envp)
{
	int		i;
	t_list	*list;
	t_node	*node;
	char	**splitted_text;

	list = new_list();
	i = -1;
	while (envp[++i])
	{
		splitted_text = ft_split(envp[i], '=');
		if (contain_chars(splitted_text[0], "OLDPWD"))
		{
			free(splitted_text[1]);
			splitted_text[1] = NULL;
		}
		node = new_node(splitted_text[0], splitted_text[1]);
		add(list, node);
		free_array(splitted_text);
	}
	return (list);
}

t_string	*init_envir(char **envir)
{
	int			i;
	t_string	*result;

	i = -1;
	while (envir[++i])
		;
	result = malloc(sizeof(t_string) * (i + 1));
	i = -1;
	while (envir[++i])
		result[i] = ft_strdup(envir[i]);
	result[i] = NULL;
	return (result);
}

void	set_shell_lvl(t_data *data)
{
	t_node		*shell_lvl_node;
	t_string	new_lvl_string;
	int			current_lvl;

	shell_lvl_node = find_node_with_key(data->env_list, "SHLVL");
	if (!shell_lvl_node)
		return ;
	current_lvl = basic_atoi(shell_lvl_node->value);
	current_lvl++;
	new_lvl_string = ft_itoa(current_lvl);
	update_with_key(data->env_list, "SHLVL", new_lvl_string);
	free(new_lvl_string);
}

t_data	*data_init(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->command_table = NULL;
	data->env_list = init_env_list(envp);
	data->envir = init_envir(envp);
	data->path = NULL;
	data->pwd = ft_strdup(find_node_with_key(data->env_list, "PWD")->value);
	data->temp_dir = ft_strdup(find_node_with_key
			(data->env_list, "TMPDIR")->value);
	set_shell_lvl(data);
	data->last_status = 0;
	data->ctrl_c_pressed = 0;
	return (data);
}
