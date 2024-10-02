/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:59:19 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/30 21:31:43 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	return (ft_recursive_factorial(nb - 1) * nb);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_recursive_factorial(-8));
	return (0);
}
*/
