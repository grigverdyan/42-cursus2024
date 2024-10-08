/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:01 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:02 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = -1;
	count = 1;
	len = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--len] && s[len] == c && i < len)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
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

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	wordcount;
	char	**result;

	start = 0;
	i = -1;
	wordcount = word_count(s, c);
	result = malloc(sizeof(char *) * (wordcount + 1));
	if (!s || !result)
		return (NULL);
	while (++i < wordcount)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		result[i] = fillword(s, start, end - start);
		start = end;
	}
	result[i] = 0;
	return (result);
}
