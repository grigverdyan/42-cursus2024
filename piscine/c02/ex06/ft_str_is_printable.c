/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:01:47 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 14:39:51 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
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
	char s[] = "AAA\n";
	printf("%d\n", ft_str_is_printable(s));
}

*/
