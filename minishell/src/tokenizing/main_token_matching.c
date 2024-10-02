/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_token_matching.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:09 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:10 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirection_input_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_split(token, '<');
	token_len = ft_strlen(token);
	if ((token_len == 1) && (token[0] == '<'))
	{
		add_tok(tokens_list, new_tok_node(RED_INPUT, "<"));
		return (free_array(temp));
	}
	if ((token[0] == '<') && token[1])
		add_tok(tokens_list, new_tok_node(RED_INPUT, "<"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(RED_INPUT, "<"));
	}
	if (token[token_len - 2] && (token[token_len - 1] == '<'))
		add_tok(tokens_list, new_tok_node(RED_INPUT, "<"));
	free_array(temp);
}

void	redirection_output_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_split(token, '>');
	token_len = ft_strlen(token);
	if ((token_len == 1) && (token[0] == '>'))
	{
		add_tok(tokens_list, new_tok_node(RED_OUTPUT, ">"));
		return (free_array(temp));
	}
	if ((token[0] == '>') && token[1])
		add_tok(tokens_list, new_tok_node(RED_OUTPUT, ">"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(RED_OUTPUT, ">"));
	}
	if (token[token_len - 2] && (token[token_len - 1] == '>'))
		add_tok(tokens_list, new_tok_node(RED_OUTPUT, ">"));
	free_array(temp);
}

void	redirection_output_app_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_str_split(token, ">>");
	token_len = ft_strlen(token);
	if ((token_len == 2) && (token[0] == '>') && (token[1] == '>'))
	{
		add_tok(tokens_list, new_tok_node(RED_OUT_APP, ">>"));
		return (free_array(temp));
	}
	if ((token[0] == '>') && (token[1] == '>') && token[2])
		add_tok(tokens_list, new_tok_node(RED_OUT_APP, ">>"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(RED_OUT_APP, ">>"));
	}
	if (token[token_len - 3] && (token[token_len - 2] == '>') && \
		(token[token_len - 1] == '>'))
		add_tok(tokens_list, new_tok_node(RED_OUT_APP, ">>"));
	free_array(temp);
}

void	here_doc_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_str_split(token, "<<");
	token_len = ft_strlen(token);
	if ((token_len == 2) && (token[0] == '<') && (token[1] == '<'))
	{
		add_tok(tokens_list, new_tok_node(HERE_DOC, "<<"));
		return (free_array(temp));
	}
	if ((token[0] == '<') && (token[1] == '<') && token[2])
		add_tok(tokens_list, new_tok_node(HERE_DOC, "<<"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(HERE_DOC, "<<"));
	}
	if (token[token_len - 3] && (token[token_len - 2] == '<') && \
		(token[token_len - 1] == '<'))
		add_tok(tokens_list, new_tok_node(HERE_DOC, "<<"));
	free_array(temp);
}

void	pipe_token(char *token, t_tok_list *tokens_list)
{
	int		token_len;
	char	**temp;
	int		idx;

	idx = -1;
	temp = ft_split(token, '|');
	token_len = ft_strlen(token);
	if ((token_len == 1) && (token[0] == '|'))
	{
		add_tok(tokens_list, new_tok_node(PIPE, "|"));
		return (free_array(temp));
	}
	if ((token[0] == '|') && token[1])
		add_tok(tokens_list, new_tok_node(PIPE, "|"));
	while (temp[++idx])
	{
		match_token(temp[idx], tokens_list);
		if (temp[idx + 1] != NULL)
			add_tok(tokens_list, new_tok_node(PIPE, "|"));
	}
	if (token[token_len - 2] && (token[token_len - 1] == '|'))
		add_tok(tokens_list, new_tok_node(PIPE, "|"));
	free_array(temp);
}
