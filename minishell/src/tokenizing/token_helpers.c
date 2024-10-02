/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:13 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:14 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_cmp(char *str1, char *str2)
{
	int	idx;

	idx = 0;
	while (str1[idx] && str2[idx] && str1[idx] == str2[idx])
		idx++;
	return (str1[idx] - str2[idx]);
}

int	str_len(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		;
	return (idx);
}

int	starts_with(char *token, char start)
{
	if (token && (token[0] == start))
		return (1);
	return (0);
}

int	starts_with_mul(char *token, char *start)
{
	int	idx;

	idx = -1;
	if (token)
	{
		while (start[++idx])
			if (token[0] == start[idx])
				return (1);
	}
	return (0);
}

int	starts_with_string(char *str1, char *str2)
{
	int	idx;

	idx = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[idx] == str2[idx])
		idx++;
	if (str2[idx] == '\0')
		return (1);
	return (0);
}
