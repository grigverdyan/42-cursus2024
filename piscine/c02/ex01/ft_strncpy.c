/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:38:20 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/28 19:09:42 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char src[100] = "shabatic shuyt urbat";
	char dest[100]  = "sax lav klni";
	int n = 4;
//	printf("My -> %s\n", ft_strncpy(dest, src, n));
	printf("00 -> %s\n", strncpy(dest, src, n));
}

*/
