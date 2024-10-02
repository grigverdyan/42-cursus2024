/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:50 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:52 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redefine_tokens_loop(t_tok_node *temp, t_tok_node *to)
{
	while (temp && to && (temp != to->next))
	{
		if (temp->key == RED_INPUT && temp->next && (temp->next->key == WORD))
			temp->next->key = FILE;
		if (temp->key == RED_OUTPUT && temp->next && (temp->next->key == WORD))
			temp->next->key = FILE;
		if (temp->key == RED_OUT_APP && temp->next && (temp->next->key == WORD))
			temp->next->key = FILE;
		if (temp->key == HERE_DOC && temp->next && (temp->next->key == WORD))
			temp->next->key = DELIMITER;
		if (temp->key == PIPE && temp->next && (temp->next->key == WORD))
			temp->next->key = CMD;
		if (temp->key == AND_OR && temp->next && (temp->next->key == WORD))
			temp->next->key = CMD;
		if (temp->key == OR_IF && temp->next && (temp->next->key == WORD))
			temp->next->key = CMD;
		if (temp->key == WORD && temp->prev && temp->prev->key == FILE)
			temp->key = CMD;
		if (temp->key == WORD && temp->prev && (temp->prev->key == FILE || \
											temp->prev->key == DELIMITER) && \
			temp->next && temp->next->key == OPTION)
			temp->key = CMD;
		temp = temp->next;
	}
}

void	token_counter(t_tok_node *temp, int *array)
{
	if (temp->key == CMD)
		array[0]++;
	if (temp->key == RED_INPUT || temp->key == RED_OUTPUT || \
												temp->key == RED_OUT_APP)
		array[1]++;
	if (temp->key == FILE)
		array[2]++;
	if (temp->key == HERE_DOC)
		array[3]++;
	if (temp->key == DELIMITER)
		array[4]++;
}
