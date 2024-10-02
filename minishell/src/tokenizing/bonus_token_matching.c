/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_token_matching.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:07 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:08 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_for_option(char *token)
{
	if (starts_with(token, '-') || starts_with(++token, '-'))
		return (1);
	return (0);
}

int	check_for_word(char *token)
{
	int	idx;

	idx = -1;
	while (token[++idx])
		if (!(token[idx] >= 'a' && token[idx] <= 'z') || \
		!(token[idx] >= 'A' && token[idx] <= 'Z') || \
		!(token[idx] >= '0' && token[idx] <= '9') || \
		!consist(token[idx], "%=+‘“()$/_-.?*~"))
			return (1);
	return (0);
}

void	and_if_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_str_split(token, "&&");
	token_len = ft_strlen(token);
	if ((token_len == 2) && (token[0] == '&') && (token[1] == '&'))
	{
		add_tok(tokens_list, new_tok_node(AND_OR, "&&"));
		return (free_array(temp));
	}
	if ((token[0] == '&') && (token[1] == '&') && token[2])
		add_tok(tokens_list, new_tok_node(AND_OR, "&&"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(AND_OR, "&&"));
	}
	if (token[token_len - 3] && (token[token_len - 2] == '&') && \
		(token[token_len - 1] == '&'))
		add_tok(tokens_list, new_tok_node(AND_OR, "&&"));
	free_array(temp);
}

void	or_if_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_str_split(token, "||");
	token_len = ft_strlen(token);
	if ((token_len == 2) && (token[0] == '|') && (token[1] == '|'))
	{
		add_tok(tokens_list, new_tok_node(OR_IF, "||"));
		return (free_array(temp));
	}
	if ((token[0] == '|') && (token[1] == '|') && token[2])
		add_tok(tokens_list, new_tok_node(OR_IF, "||"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(OR_IF, "||"));
	}
	if (token[token_len - 3] && (token[token_len - 2] == '|') && \
		(token[token_len - 1] == '|'))
		add_tok(tokens_list, new_tok_node(OR_IF, "||"));
	free_array(temp);
}
