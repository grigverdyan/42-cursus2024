/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:53 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:11:58 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pattern(t_wildcard *w_env, int depth, int slash, t_dirent *dir_format)
{
	if ((!w_env->token[depth] || !w_env->token[depth + 1]) && \
		ft_strmatch(w_env->path_parts[slash], dir_format->d_name, 0, 0) && \
		(ft_same_str(dir_format->d_name, w_env->path_parts[slash]) || \
		dir_format->d_name[0] != '.' || w_env->path_parts[slash][0] == '.'))
		return (1);
	return (0);
}

int	check_path_childs(t_wildcard *w_env, int slash, t_dirent *dir_format)
{
	if (ft_strmatch(w_env->path_parts[slash], dir_format->d_name, 0, 0) && \
		(ft_same_str(dir_format->d_name, w_env->path_parts[slash]) || \
		dir_format->d_name[0] != '.' || w_env->path_parts[slash][0] == '.'))
		return (1);
	return (0);
}

void	add_wild_argument(t_tok_list *tokens_list, char *arg)
{
	char		*ptr;
	DIR			*dir;

	if (g_data->wildcard_ends_slash)
	{
		dir = opendir(arg);
		if (dir)
		{
			ptr = append_slash(arg);
			add_tok(tokens_list, new_tok_node(ARGUMENT, clean_path(ptr)));
			g_data->wildcard_result = 1;
			guard_free(ptr);
			closedir(dir);
		}
	}
	else
	{
		add_tok(tokens_list, new_tok_node(ARGUMENT, clean_path(arg)));
		g_data->wildcard_result = 1;
	}
}

void	process_wildcard(t_wildcard *w_env, char *start_path, int depth)
{
	int			slash;
	char		*new_path;
	DIR			*directory;
	t_dirent	*dir_format;

	slash = path_slash_count(start_path);
	if (!depth)
		depth += ft_strlen(start_path) - 1;
	directory = opendir(start_path);
	while (w_env->token[depth] && w_env->token[depth] != '/')
		depth++;
	if (!directory)
		return ;
	dir_format = readdir(directory);
	while (w_env->path_parts[slash] && dir_format)
	{
		new_path = join_free(start_path, ft_strjoin("/", dir_format->d_name));
		if (check_pattern(w_env, depth, slash, dir_format))
			add_wild_argument(w_env->tokens_list, new_path);
		if (check_path_childs(w_env, slash, dir_format))
			process_wildcard(w_env, new_path, depth + 1);
		dir_format = readdir(directory);
		guard_free(new_path);
	}
	closedir(directory);
}

void	wildcard_expansion(t_tok_list *tokens_list, char *token)
{
	t_wildcard	w_env;
	char		*start_path;

	if (!consist('*', token))
		return ;
	if (ends_with_char(token, '/'))
		g_data->wildcard_ends_slash = 1;
	w_env.token = token;
	w_env.tokens_list = tokens_list;
	w_env.path_parts = ft_split(token, '/');
	start_path = create_wildpath(token);
	process_wildcard(&w_env, start_path, 0);
	if (g_data->wildcard_result == 0)
		add_tok(tokens_list, new_tok_node(ARGUMENT, token));
	g_data->wildcard_result = 0;
	g_data->wildcard_ends_slash = 0;
	guard_free(start_path);
	free_array(w_env.path_parts);
}
