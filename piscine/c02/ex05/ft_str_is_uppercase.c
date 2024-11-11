/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:54:59 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 14:38:32 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
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
	char s[] = "AAA";
	printf("%d\n", ft_str_is_uppercase(s));
}

*/
