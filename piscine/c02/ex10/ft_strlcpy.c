/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:49:05 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 14:42:25 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*

#include <stdio.h>
#include <string.h>

int main()
{
	char src[100] = "shabatic shuyt urbat";
	char dest[100]  = "sax lav klni";
	int n = 4;
//	printf("My -> %d     %s\n", ft_strlcpy(dest, src, n), dest);
	printf("00 -> %d     %s\n", strlcpy(dest, src, n), dest);
}
*/
