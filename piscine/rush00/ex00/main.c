/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:50:57 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/14 23:06:54 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int col, int row);
int		ft_atoi(const char *str);
int		is_space(char c);

int	main(int argc, char **argv)
{
	int	row;
	int	col;

	if (argc == 3)
	{
		col = ft_atoi(argv[1]);
		row = ft_atoi(argv[2]);
		if (col < 1 || row < 1)
			write(1, "Incorrect input\n", 16);
		else
			rush(col, row);
	}
	else
		write(1, "Incorrect input\n", 16);
	return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		++i;
	}
	return (sign * num);
}
