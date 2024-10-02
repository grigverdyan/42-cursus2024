/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:55 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:56 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*shift_left(char *arg, int idx)
{
	int	jdx;

	jdx = -1;
	if (!arg[idx + 2])
		return (arg);
	while (arg[idx + 2 + (++jdx)])
	{
		arg[idx + jdx] = arg[idx + 2 + jdx];
	}
	arg[idx + jdx] = '\0';
	return (arg);
}

char	*join_free(char const *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*res;

	size1 = -1;
	size2 = -1;
	i = -1;
	while (s1[++size1])
		;
	while (s2[++size2])
		;
	res = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	while (++i < size1)
		res[i] = s1[i];
	while (i - size1 < size2)
	{
		res[i] = s2[i - size1];
		i++;
	}
	res[i] = 0;
	free(s2);
	return (res);
}
