/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:10:21 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/30 19:04:49 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	if (!str)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}
/*

#include <stdio.h>

int	main()
{
//	char *s = 0;
	char s[] = "SHABATIC SHUT URBaT, erankyun burg 13";
	printf("%s\n", ft_strlowcase(s));
}

*/
