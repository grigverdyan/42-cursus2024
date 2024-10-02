/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:28:16 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:28:30 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	guard_free(void *data)
{
	if (data)
		free(data);
	data = NULL;
}

void	free_data(void)
{
	rl_clear_history();
	free_list(g_data->env_list);
	guard_free(g_data->pwd);
	guard_free(g_data->temp_dir);
	guard_free(g_data->builtins);
	guard_free(g_data->envir);
	guard_free(g_data->path);
	guard_free(g_data);
}

void	free_and_exit(int status)
{
	free_data();
	exit(status);
}

void	set_data_path(t_list *list)
{
	int		i;
	char	**file_path;
	char	**withbackslash;
	t_node	*path_node;

	file_path = NULL;
	withbackslash = NULL;
	free_array(g_data->path);
	path_node = find_node_with_key(list, "PATH");
	if (!path_node)
	{
		g_data->path = NULL;
		return ;
	}
	file_path = ft_split(path_node->value, ':');
	i = -1;
	while (file_path[++i])
		;
	withbackslash = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (file_path[++i])
		withbackslash[i] = ft_strjoin(file_path[i], "/");
	withbackslash[i] = NULL;
	free_array(file_path);
	g_data->path = withbackslash;
}

char	*get_command_path(char *command)
{
	char	*file_path;
	char	*result;
	int		i;

	result = NULL;
	i = -1;
	set_data_path(g_data->env_list);
	if (!g_data->path)
		return (NULL);
	while (g_data->path[++i])
	{
		file_path = ft_strjoin(g_data->path[i], command);
		if (access(file_path, X_OK) == 0)
		{
			result = file_path;
			break ;
		}
		free(file_path);
	}
	return (result);
}
