/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:17 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:18 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	contain_chars(char *str, char *substr)
{
	int	i;
	int	j;
	int	contains;

	i = -1;
	contains = 0;
	while (str[++i])
	{
		contains = 0;
		j = -1;
		while (substr[++j])
		{
			if (str[i + j] != substr[j])
			{
				contains = 0;
				break ;
			}
			contains = 1;
		}
		if (contains)
			return (1);
	}
	return (0);
}

int	consist(char chr, char *spec_chars)
{
	int	idx;

	idx = -1;
	while (spec_chars[++idx])
	{
		if (spec_chars[idx] == chr)
		{
			if (spec_chars[idx + 1])
			{
				if (spec_chars[idx + 1] == chr)
					return (0);
			}
			return (1);
		}
	}
	return (0);
}

int	has_quotes(char *token, t_tok_list *tokens_list)
{
	int	idx;

	idx = -1;
	while (token[++idx])
	{
		if (token[idx] == '\'' || token[idx] == '\"')
		{
			add_tok(tokens_list, new_tok_node(WORD, token));
			return (1);
		}
	}
	return (0);
}

void	match_token(char *token, t_tok_list *tokens_list)
{
	if (contain_chars(token, ">>"))
		redirection_output_app_token(token, tokens_list);
	else if (contain_chars(token, "<<"))
		here_doc_token(token, tokens_list);
	else if (consist('<', token))
		redirection_input_token(token, tokens_list);
	else if (consist('>', token))
		redirection_output_token(token, tokens_list);
	else if (consist('|', token))
		pipe_token(token, tokens_list);
	else if (contain_chars(token, "$?"))
		parentheses_middleware(tokens_list, EXIT_STATUS, token, 'R');
	else if (contain_chars(token, "&&"))
		and_if_token(token, tokens_list);
	else if (contain_chars(token, "||"))
		or_if_token(token, tokens_list);
	else if (check_for_option(token))
		parentheses_middleware(tokens_list, OPTION, token, 'R');
	else if (consist('*', token))
		wildcard_expansion(tokens_list, token);
	else if (check_for_word(token))
		check_both_parentheses(tokens_list, WORD, token);
	else
		add_tok(tokens_list, new_tok_node(NO_TOKEN, token));
}

t_tok_list	*tokenizer(char **line)
{
	int			idx;
	t_tok_list	*tokens_list;

	idx = -1;
	if (!line)
		return (NULL);
	tokens_list = new_tok_list();
	idx = -1;
	while (line[++idx])
	{
		if (has_quotes(line[idx], tokens_list))
			continue ;
		match_token(line[idx], tokens_list);
	}
	free_array(line);
	return (tokens_list);
}
