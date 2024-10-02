/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:09:57 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:09:58 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	path_slash_count(char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == '/' && i != 0)
			count++;
	return (count);
}

int	ft_strmatch(char *s1, char *s2, int i, int j)
{
	int	k;

	if ((!s1[i] || (!s1[i + 1] && s1[i] == '*')) && !s2[j])
		return (1);
	if (!s2[j])
		return (0);
	if (s1[i] == s2[j])
		return (ft_strmatch(s1, s2, i + 1, j + 1));
	k = j;
	if (s1[i] == '*')
		while (s2[k])
			if (ft_strmatch(s1, s2, i + 1, k++))
				return (1);
	if (s1[i] == '*' && s1[i + 1] == s2[j + 1])
		return (ft_strmatch(s1, s2, i + 1, j + 1));
	if (s1[i] == '*')
		return (ft_strmatch(s1, s2, i, j + 1));
	return (0);
}

char	*create_wildpath(char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (s[len] && s[len] != '*')
		len++;
	dest = (char *)malloc(len + 2);
	if (!dest)
		return (NULL);
	while (s[i] && (s[i] == '/' || s[i] == '.'))
	{
		dest[i] = s[i];
		i++;
	}
	if (i == 0 || s[i - 1] == '/')
	{
		dest[i] = '.';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*append_slash(char *arg)
{
	int		idx;
	int		len;
	char	*new;

	idx = -1;
	len = ft_strlen(arg);
	new = malloc((len + 1));
	while (++idx < len)
		new[idx] = arg[idx];
	new[idx++] = '/';
	new[idx] = '\0';
	return (new);
}

char	*clean_path(char *arg)
{
	int	idx;

	idx = -1;
	while (arg[++idx])
	{
		if (arg[idx] == '.' && arg[idx + 1] && arg[idx + 1] == '/')
		{
			if ((arg[idx - 1] && arg[idx - 1] != '.') || \
				(arg[idx + 2] && arg[idx + 2] != '/'))
			{
				return (shift_left(arg, idx));
			}
		}
	}
	return (arg);
}
