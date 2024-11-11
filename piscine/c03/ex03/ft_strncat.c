/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:59:04 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/18 21:05:12 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (src[j] && j < nb)
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
	int	n = 6;

	printf("my -> %s\n", ft_strncat(s1, s2, n));
//	printf("00 -> %s\n", strncat(s1, s2, n));
}

*/
