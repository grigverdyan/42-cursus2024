/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:18 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:26:19 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	on_no_argument(void)
{
	char	ch[256];
	t_node	*home_node;

	home_node = find_node_with_key(g_data->env_list, "HOME");
	if (!home_node)
		return (print_error_message("exit", HOME_NOT_SET));
	if (!chdir(home_node->value))
		return (change_cwd(getcwd(ch, sizeof(ch))));
	return (1);
}

void	no_such_file(t_string path)
{
	t_string	error_message;

	error_message = ft_strjoin("cd: ", path);
	print_error_message(error_message, NO_SUCH_FILE_OR_DIR);
	free(error_message);
}

int	cd(char **path)
{
	char	ch[256];

	if (!path[0])
		return (on_no_argument());
	if (!chdir(path[0]))
		return (change_cwd(getcwd(ch, sizeof(ch))));
	else
		no_such_file(path[0]);
	return (1);
}
