/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:18:56 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/30 19:01:40 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
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
	char *s1 = NULL;
//	char s[] = "jdfaAjgdfha\ngdf";
	printf("%d\n", ft_str_is_alpha(s1));
}

*/
