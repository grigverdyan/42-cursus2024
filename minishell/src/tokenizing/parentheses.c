/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parentheses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:11 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:12 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ends_with_char(char *str, char chr)
{
	int	len;
	int	par_count;

	if (!str || !chr)
		return (0);
	len = ft_strlen(str);
	par_count = 0;
	if ((len != 0) && str[len - 1] == chr)
	{
		while ((--len >= 0) && (str[len] == chr))
			par_count++;
		return (par_count);
	}
	return (0);
}

int	starts_with_char(char *str, char chr)
{
	int	len;
	int	idx;
	int	par_count;

	if (!str || !chr)
		return (0);
	len = ft_strlen(str);
	par_count = 0;
	idx = -1;
	if ((len != 0) && str[0] == chr)
	{
		while ((++idx < len) && (str[idx] == chr))
			par_count++;
		return (par_count);
	}
	return (0);
}

void	parentheses_middleware(t_tok_list *tokens_list, int token, \
														char *temp, char dir)
{
	int	idx;
	int	times;

	(void)token;
	idx = -1;
	if (dir == 'R')
	{
		times = ends_with_char(temp, ')');
		if ((ft_strlen(temp) - times) > 0)
		{
			temp[ft_strlen(temp) - times] = '\0';
			add_tok(tokens_list, new_tok_node(token, temp));
		}
		while (--times >= 0)
			add_tok(tokens_list, new_tok_node(R_BRACE, ")"));
		return ;
	}
	times = starts_with_char(temp, '(');
	while (++idx < times)
		add_tok(tokens_list, new_tok_node(L_BRACE, "("));
	idx = -1;
	while (++idx < times)
		temp++;
	if (ft_strlen(temp) != 0)
		add_tok(tokens_list, new_tok_node(token, temp));
}

void	check_both_parentheses(t_tok_list *tokens_list, int token, char *temp)
{
	int	idx;
	int	times;

	idx = -1;
	times = starts_with_char(temp, '(');
	while (++idx < times)
		add_tok(tokens_list, new_tok_node(L_BRACE, "("));
	idx = -1;
	while (++idx < times)
		temp++;
	times = ends_with_char(temp, ')');
	if ((ft_strlen(temp) - times) > 0)
	{
		temp[ft_strlen(temp) - times] = '\0';
		add_tok(tokens_list, new_tok_node(token, temp));
	}
	while (--times >= 0)
		add_tok(tokens_list, new_tok_node(R_BRACE, ")"));
}
