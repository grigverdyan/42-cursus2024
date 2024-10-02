/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:53:46 by grverdya          #+#    #+#             */
/*   Updated: 2023/11/02 00:59:41 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (ft_recursive_power(nb, power - 1) * nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_recursive_power(-3, 5));
	return (0);
}
*/
