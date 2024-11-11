/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:27:26 by grverdya          #+#    #+#             */
/*   Updated: 2023/11/02 02:30:11 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <  nb && i < 46341)
		++i;
	if (i * i == nb)
		return (i);
	return (0);
}

#include <stdio.h>
#include <limits.h>
int	main()
{
	printf("%d", ft_sqrt(256));
	return (0);
}

