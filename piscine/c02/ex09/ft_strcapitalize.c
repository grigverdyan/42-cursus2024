/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:32:47 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 14:42:01 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

int	is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (str);
	res = ft_strlowcase(str);
	i = 0;
	while (res[i])
	{
		if (i == 0 && is_alpha(str[0]))
			str[i] -= 32;
		else if (!is_alpha(str[i]) && !is_digit(str[i])
			&& str[i + 1] && is_alpha(str[i + 1]))
		{
			++i;
			str[i] -= 32;
		}
		++i;
	}
	return (res);
}
/*

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
//	char s[] = "SHABATIC SHUT URBaT, erankyun burg 13";
	printf("%s\n", ft_strcapitalize(argv[1]));
}

*/
