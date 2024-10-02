/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:19 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:21 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	close_fds(int **fds, int i_len)
{
	int	i;

	i = -1;
	while (++i < i_len)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		free(fds[i]);
	}
	free(fds);
}

int	change_cwd(char *new_pwd)
{
	t_node		*old_pwd;
	t_node		*pwd;

	old_pwd = find_node_with_key(g_data->env_list, "OLDPWD");
	pwd = find_node_with_key(g_data->env_list, "PWD");
	if (old_pwd)
	{
		if (old_pwd->value)
			free(old_pwd->value);
		old_pwd->value = g_data->pwd;
	}
	if (pwd)
	{
		if (pwd->value)
			free(pwd->value);
		pwd->value = ft_strdup(new_pwd);
	}
	g_data->pwd = ft_strdup(new_pwd);
	return (0);
}

char	command_exists(char *command)
{
	char	*file_path;
	int		i;

	i = -1;
	while (g_data->path[++i])
	{
		file_path = ft_strjoin(g_data->path[i], command);
		if (access(file_path, X_OK) == 0)
		{
			free(file_path);
			return (TRUE);
		}
		free(file_path);
	}
	return (FALSE);
}

void	*error(char *msg, int code)
{
	ft_putstr_fd("minishell: syntax error near ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	g_data->last_status = code;
	return (NULL);
}
