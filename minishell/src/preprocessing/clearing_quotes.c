/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:12:39 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:12:40 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_char(t_string string, int *i, int *len)
{
	if (string[*i] == '\'')
	{
		while (string[++(*i)] != '\'')
			(*len)++;
		i++;
	}
	else if (string[*i] == '\"')
	{
		while (string[++(*i)] != '\"')
			(*len)++;
		(*i)++;
	}
	else
	{
		if (*i > 1 && (string[*i - 1] == '\''
				|| string[*i - 1] == '\"'))
			(*len)++;
		(*len)++;
	}
}

int	cleared_len(t_string string)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (string[++i])
		handle_char(string, &i, &len);
	return (len);
}

t_string	clear_quotes(t_string string)
{
	int			i;
	int			j;
	t_string	new_str;

	i = -1;
	j = -1;
	new_str = malloc(cleared_len(string) + 1);
	while (string[++i])
	{
		if (string[i] == '\'')
			while (string[++i] != '\'')
				new_str[++j] = string[i];
		else if (string[i] == '\"')
			while (string[++i] != '\"')
				new_str[++j] = string[i];
		else
			new_str[++j] = string[i];
	}
	new_str[++j] = 0;
	return (new_str);
}
