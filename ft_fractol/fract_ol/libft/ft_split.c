/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:20:51 by stadevos          #+#    #+#             */
/*   Updated: 2022/04/06 20:30:17 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	delimeter_count(char const *s, char c)
{
	size_t			idx;
	unsigned int	count;

	idx = 0;
	count = 0;
	while (s[idx])
	{
		if (s[idx] == c)
			++idx;
		else
		{
			++count;
			while (s[idx] != c && s[idx])
				++idx;
		}
	}
	return (count);
}

static size_t	chr_count(char const *s, char c, size_t start)
{
	size_t	count;

	count = 0;
	while (s[start] == c && s[start])
		++start;
	while (s[start])
	{
		if (s[start] == c)
			break ;
		count++;
		start++;
	}
	return (count + 1);
}

static void	ft_free(char **ptr, size_t ptr_idx)
{
	size_t	i;

	i = 0;
	while (i < ptr_idx)
	{
		free(ptr[i]);
		i++;
	}
}

static int	spalloc(char **ptr, char const *str, char c, size_t word_count)
{
	size_t	ptr_idx;
	size_t	str_idx;
	size_t	count;
	size_t	ptr_str_idx;

	ptr_idx = 0;
	str_idx = 0;
	while (ptr_idx < word_count)
	{
		count = chr_count(str, c, str_idx);
		ptr[ptr_idx] = (char *)malloc(sizeof(char) * count);
		if (!ptr[ptr_idx])
		{
			ft_free(ptr, ptr_idx);
			return (0);
		}
		ptr_str_idx = 0;
		while (str[str_idx] == c)
			str_idx++;
		while (ptr_str_idx < count - 1)
			ptr[ptr_idx][ptr_str_idx++] = str[str_idx++];
		ptr[ptr_idx++][ptr_str_idx] = '\0';
		str_idx++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_count;
	int		is_alloc;

	word_count = delimeter_count(s, c);
	ptr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!ptr)
		return (NULL);
	is_alloc = spalloc(ptr, s, c, word_count);
	ptr[word_count] = NULL;
	if (is_alloc == 0)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
