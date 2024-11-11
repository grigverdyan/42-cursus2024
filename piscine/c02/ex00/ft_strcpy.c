/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:13:12 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/19 00:13:33 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	s1[] = "alooooooo00";
	char	s2[] = "aloooy";

//	printf("my -> %s\n", ft_strcpy(s1, s2));
	printf("00 -> %s\n", strcpy(s1, s2));
}

*/
