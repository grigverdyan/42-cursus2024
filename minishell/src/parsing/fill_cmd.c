/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:36 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:37 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_string	fill_command(t_tok_node *from, t_tok_node *to)
{
	while (from && to && (from != to->next))
	{
		if (from->key == CMD)
			return (ft_strdup(from->value));
		from = from->next;
	}
	return (NULL);
}

t_string	*fill_params(t_tok_node *from, t_tok_node *to)
{
	int			pos;
	t_string	*string;
	int			params_len;

	pos = -1;
	params_len = count_params(from, to);
	string = malloc((params_len + 1) * sizeof(t_string));
	while (from && to && (from != to->next))
	{
		if (from->key == OPTION || from->key == ARGUMENT)
			string[++pos] = ft_strdup(from->value);
		from = from->next;
	}
	string[++pos] = NULL;
	return (string);
}

int	fill_input(t_tok_node *from, t_tok_node *to)
{
	int	old;
	int	in_fd;

	old = 0;
	in_fd = 0;
	while (from && to && (from != to->next))
	{
		if (from->key == RED_INPUT && from->next)
		{
			if (old != 0)
				close(old);
			in_fd = open(from->next->value, O_RDONLY);
			old = in_fd;
		}
		else if (from == to && from->key == DELIMITER && in_fd != -1)
			in_fd = 0;
		from = from->next;
	}
	return (in_fd);
}

int	fill_output(t_tok_node *from, t_tok_node *to)
{
	int	old;
	int	out_fd;

	old = 1;
	out_fd = 1;
	while (from && to && (from != to->next))
	{
		if (from->key == RED_OUTPUT && from->next)
		{
			if (old != 1)
				close(old);
			out_fd = open(from->next->value, O_CREAT | O_RDWR | O_TRUNC, 0777);
			old = out_fd;
		}
		else if (from->key == RED_OUT_APP && from->next)
		{
			if (old != 1)
				close(old);
			out_fd = open(from->next->value, O_CREAT | O_RDWR | O_APPEND, 0777);
			old = out_fd;
		}
		from = from->next;
	}
	return (out_fd);
}

int	fill_error(t_tok_node *from, t_tok_node *to)
{
	(void)to;
	(void)from;
	return (2);
}
