/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:30:55 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 14:37:12 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			++i;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>

int	main()
{
	char *s = NULL;
//	char s[] = "akhdgahdgahgdjhadgA";
	printf("%d\n", ft_str_is_lowercase(s));
}

*/
