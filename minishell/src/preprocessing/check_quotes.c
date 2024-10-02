/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:12:36 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:12:37 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *cmd)
{
	int	quote;

	while (1)
	{
		while (is_space(*cmd))
			cmd++;
		if (*cmd == '\0')
			break ;
		if (*cmd == '"' || *cmd == '\'')
		{
			quote = *cmd++;
			while (*cmd && *cmd != quote)
				cmd++;
			if (*cmd == '\0')
				return (0);
			cmd++;
			continue ;
		}
		else
		{
			cmd++;
			continue ;
		}
	}
	return (1);
}

int	logic_or_pipe(char *inpt)
{
	int	idx;
	int	len;
	int	pipe;
	int	logic;

	idx = -1;
	pipe = 0;
	logic = 0;
	len = ft_strlen(inpt);
	if (contain_chars(inpt, "||") || contain_chars(inpt, "&&") || \
		contain_chars(inpt, "(") || contain_chars(inpt, ")"))
		logic++;
	while (inpt[++idx])
		if ((inpt[0] == '|' && inpt[1] && inpt[1] != '|') || \
		(inpt[len - 1] == '|' && inpt[len - 2] && inpt[len - 2] != '|') || \
		(inpt[idx - 1] != '|' && inpt[idx] == '|' && inpt[idx + 1] != '|'))
			pipe++;
	if (logic != 0)
		g_data->pipe_logic_mode = _LOGIC;
	else if (pipe != 0)
		g_data->pipe_logic_mode = _PIPE;
	if (!(pipe && logic))
		return (1);
	return (0);
}

int	invalid_logic_operator(char *inpt)
{
	if (contain_chars(inpt, "(&") || contain_chars(inpt, "&)"))
		return (0);
	if (contain_chars(inpt, "(|") || contain_chars(inpt, "|)"))
		return (0);
	if (contain_chars(inpt, "()") || contain_chars(inpt, ")("))
		return (0);
	return (1);
}

int	invalid_start_and_end(char *inpt)
{
	int	idx;
	int	len;

	idx = -1;
	len = ft_strlen(inpt);
	while (is_space(inpt[++idx]))
		;
	if (consist(inpt[idx], "|&)"))
		return (FALSE);
	while (is_space(inpt[--len]))
		;
	if (consist(inpt[len], "|&("))
		return (FALSE);
	return (TRUE);
}
