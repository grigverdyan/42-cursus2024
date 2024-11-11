/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:26:15 by grverdya          #+#    #+#             */
/*   Updated: 2023/11/02 00:39:02 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '-' || base[0] == '+')
		return (0);
	i = -1;
	while (base[++i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j]
				|| base[j] == '+' || base[j] == '-')
				return (0);
			++j;
		}
	}
	return (1);
}

void	recursive_run(long n, int len, char *base)
{
	if (n / len != 0)
		recursive_run(n / len, len, base);
	write(1, &base[n % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;

	len = ft_strlen(base);
	if (len < 2 || !check_base(base))
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	recursive_run(n, len, base);
}
/*
#include <limits.h>
int main()
{
	ft_putnbr_base(INT_MIN, "0123456789abcdeeef");
}
*/
