/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:49:38 by grverdya          #+#    #+#             */
/*   Updated: 2023/11/02 00:53:20 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	i = 0;
	res = 1;
	while (i < power)
	{
		res *= nb;
		++i;
	}
	return (res);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_iterative_power(4, 4));
	return (0);
}
*/
