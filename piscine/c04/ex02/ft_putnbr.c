/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:33:13 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/30 19:35:59 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n / 10 == 0)
	{
		ft_putchar(n + '0');
		return ;
	}
	else
		ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}
/*
#include <limits.h>

int	main()
{
	int	number = INT_MIN;
	ft_putnbr(number);
	return (0);	
}

*/
