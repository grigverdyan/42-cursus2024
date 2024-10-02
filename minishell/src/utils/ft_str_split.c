/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:02 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:03 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	contains_str(const char *container, char *str)
{
	size_t	i;

	i = -1;
	while (str[++i] && container[i] == str[i])
		;
	return (i == ft_strlen(str));
}

static size_t	word_count(char const *s, char *str)
{
	size_t	count;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	i = 0;
	count = 1;
	while (s[i] && contains_str(s + i, str))
		i += str_len;
	if (i == ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (contains_str(s + i, str))
		{
			if (s[i + str_len] && !contains_str(s + i + str_len, str))
				count++;
			i += str_len;
		}
		else
			i++;
	}
	return (count);
}

static char	*fillword(const char *s, size_t start, size_t len)
{
	char	*word;
	size_t	i;

	i = -1;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (++i < len)
		word[i] = s[start + i];
	word[i] = 0;
	return (word);
}

char	**ft_str_split(char const *s, char *str)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	wordcount;
	char	**result;

	start = 0;
	i = -1;
	wordcount = word_count(s, str);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!s || !result)
		return (NULL);
	while (++i < wordcount)
	{
		while (s[start] && contains_str(s + start, str))
			start += ft_strlen(str);
		end = start;
		while (s[end] && !contains_str(s + end, str))
			end++;
		result[i] = fillword(s, start, end - start);
		start = end;
	}
	result[i] = 0;
	return (result);
}
