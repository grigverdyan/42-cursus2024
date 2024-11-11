/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:07:10 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/27 16:08:50 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		ret = &str[i];
		while (str[i + j] == to_find[j] && str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (ret);
			++j;
		}
		++i;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[] = "txen pti viz dni";
	char	find[] = "pti";

	printf("My -> %s\n", ft_strstr(str, find));
//	printf("My -> %s\n", strstr(str, find));
}
*/
