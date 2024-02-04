/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:54:09 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/19 22:45:26 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	idx;
	int		sign;
	int		number;

	idx = 0;
	sign = 1;
	number = 0;
	while (is_space(str[idx]))
		idx++;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	else if (str[idx] == '+')
		idx++;
	while (ft_isdigit(str[idx]))
	{
		number *= 10;
		number += str[idx] - '0';
		idx++;
	}
	return (number * sign);
}
