/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:00:54 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/27 16:13:22 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			return (0);
		++i;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s1[] = "erankyun";
	char s2[] = "burg";
	unsigned int n = 3;

	printf("My -> %d\n", ft_strncmp(s1, s2, n));
	printf("00 -> %d\n", strncmp(s1, s2, n));

}
*/
