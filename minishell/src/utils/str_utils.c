/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:22 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:24 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	contains(char *str, char ch)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ch)
			return (1);
	}
	return (0);
}

int	ft_same_str(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}
