/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:34:33 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/27 16:07:24 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_size;

	if (size < 1)
		return (ft_strlen(src));
	dst_size = ft_strlen(dest);
	i = dst_size;
	j = 0;
	while (src[j] && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (size < dst_size)
		return (size + ft_strlen(src));
	return (dst_size + ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char dest[100] = "erankyun";
	char src[] = "burg";
	unsigned int n = 101;

//	printf("My size %u -> %s\n", ft_strlcat(dest, src, n), dest);
	printf("00 size %lu -> %s\n", strlcat(dest, src, n), dest);
}

*/
