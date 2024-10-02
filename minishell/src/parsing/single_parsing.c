/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:46 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:48 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	single_cmd_parse(t_tok_node *from, t_tok_node *to)
{
	char		*ptr;
	t_tok_node	*temp;

	temp = from;
	if (!from || !to)
		return (1);
	if (redefine_tokens(from, to) || \
		redefine_argument_token(from, to) || \
		check_undefined_word_token(from, to) || \
		check_tokens_pairs(from, to))
		return (1);
	while (temp && to && (temp != to->next))
	{
		if (temp->key != DELIMITER)
		{
			ptr = clear_quotes(temp->value);
			free(temp->value);
			temp->value = ptr;
		}
		temp = temp->next;
	}
	return (0);
}

int	redefine_tokens(t_tok_node *from, t_tok_node *to)
{
	t_tok_node	*temp;

	temp = from;
	if (!((temp->key == RED_INPUT) || (temp->key == RED_OUTPUT) || \
		(temp->key == RED_OUT_APP) || (temp->key == HERE_DOC) || \
		(temp->key == WORD)))
		return (error_int("unexpected token at start", 1));
	if (temp->key == WORD)
		temp->key = CMD;
	redefine_tokens_loop(temp, to);
	return (0);
}

int	check_tokens_pairs(t_tok_node *from, t_tok_node *to)
{
	t_tok_node	*temp;
	int			array[5];

	temp = from;
	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
	array[4] = 0;
	while (temp && to && (temp != to->next))
	{
		token_counter(temp, array);
		temp = temp->next;
	}
	if (array[1] != array[2])
		return (error_int("unmatched redirections and files", 258));
	else if (array[3] != array[4])
		return (error_int("unspecified heredoc delimiter", 258));
	return (0);
}

int	redefine_argument_token(t_tok_node *from, t_tok_node *to)
{
	t_tok_node	*temp;

	temp = from;
	while (temp && to && (temp != to->next))
	{
		if (temp->key == CMD)
		{
			while (temp->next && (temp->next->key == OPTION || \
												temp->next->key == WORD))
			{
				if (temp->next->key == WORD)
					temp->next->key = ARGUMENT;
				temp = temp->next;
			}
		}
		temp = temp->next;
	}
	return (0);
}

int	check_undefined_word_token(t_tok_node *from, t_tok_node *to)
{
	t_tok_node	*temp;

	temp = from;
	while (temp && to && (temp != to->next))
	{
		if (temp->key == WORD)
		{
			temp->key = CMD;
			break ;
		}
		temp = temp->next;
	}
	temp = from;
	while (temp && to && (temp != to->next))
	{
		if (temp->key == WORD || temp->key == NO_TOKEN)
			return (error_int("unexpected token", 1));
		temp = temp->next;
	}
	return (0);
}
