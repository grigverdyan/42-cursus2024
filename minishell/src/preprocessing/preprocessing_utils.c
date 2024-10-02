/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:12:43 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:12:44 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_env(char ch)
{
	return (ft_isdigit(ch) || ft_isalpha(ch) || ch == '_');
}

int	is_space(char chr)
{
	if (chr == '\t' || chr == '\n' || chr == '\v' || \
		chr == '\f' || chr == '\r' || chr == ' ')
		return (1);
	return (0);
}

int	is_quote(char ch, char *quote)
{
	if (ch == '\"' || ch == '\'')
	{
		if (quote)
			*quote = ch;
		return (1);
	}
	else
		return (0);
}

void	else_function(t_string str, t_string new_str, int *i, int *j)
{
	if (*i > 1 && is_token(str[*i])
		&& ((str[*i - 1] == '\"') || (str[*i - 1] == '\'')))
	{
		new_str[++(*j)] = ' ';
		new_str[++(*j)] = str[*i];
	}
	else if (is_token(str[*i])
		&& ((str[*i + 1] == '\"') || (str[*i - 1] == '\'')))
	{
		new_str[++(*j)] = str[*i];
		new_str[++(*j)] = ' ';
	}
	else
		detect_env(str, i, j, new_str);
}

void	iterate_str(t_string str, t_string new_str, int *i, int *j)
{
	while (str[++(*i)])
	{
		if (str[(*i)] == '\'')
		{
			new_str[++(*j)] = str[(*i)];
			while (str[++(*i)])
			{
				new_str[++(*j)] = str[(*i)];
				if (str[(*i)] == '\'')
					break ;
			}
		}
		else if (str[(*i)] == '\"')
		{
			new_str[++(*j)] = str[(*i)];
			while (str[++(*i)])
			{
				detect_env(str, i, j, new_str);
				if (str[(*i)] == '\"')
					break ;
			}
		}
		else
			else_function(str, new_str, i, j);
	}
}
