/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:16:45 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/18 20:56:07 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/*

#include <stdio.h>
#include <string.h>


int	main()
{
	char	s1[100] = "alo";
	char	s2[] = "b762736";

	printf("my -> %s\n", ft_strcat(s1, s2));
//	printf("00 -> %s\n", strcat(s1, s2));
}

*/
