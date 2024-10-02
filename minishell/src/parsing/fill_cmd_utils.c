/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:37 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:38 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_params(t_tok_node *from, t_tok_node *to)
{
	int	params_len;

	params_len = 0;
	while (from && to && (from != to->next))
	{
		if (from->key == OPTION || from->key == ARGUMENT)
			params_len++;
		from = from->next;
	}
	return (params_len);
}

int	fill_heredoc(t_tok_node *from, t_tok_node *to)
{
	int	len;

	len = 0;
	while (from && to && (from != to->next))
	{
		if (from->key == HERE_DOC)
			len++;
		from = from->next;
	}
	return (len);
}

int	count_delimiters(t_tok_node *from, t_tok_node *to)
{
	int	delimiters_len;

	delimiters_len = 0;
	while (from && to && (from != to->next))
	{
		if (from->key == DELIMITER)
			delimiters_len++;
		from = from->next;
	}
	return (delimiters_len);
}

t_string	*fill_delimiter(t_tok_node *from, t_tok_node *to)
{
	int			pos;
	t_string	*string;
	int			delimiters_len;

	pos = -1;
	delimiters_len = count_delimiters(from, to);
	string = malloc((delimiters_len + 1) * sizeof(t_string));
	while (from && to && (from != to->next))
	{
		if (from->key == DELIMITER)
			string[++pos] = ft_strdup(from->value);
		from = from->next;
	}
	string[++pos] = NULL;
	return (string);
}
