/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:49:42 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/30 21:31:44 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res *= nb;
		--nb;
	}
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d", ft_iterative_factorial(5));
}
*/
