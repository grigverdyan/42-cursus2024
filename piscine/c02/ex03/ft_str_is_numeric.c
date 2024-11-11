/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:26:05 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 14:36:42 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
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
//	char *s1 = NULL;
	char s[] =  "265472545273525360";
	printf("%d\n", ft_str_is_numeric(s));
}

*/
