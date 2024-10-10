/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:56:39 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/02 15:05:23 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		++i;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	number = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (number > INT_MAX)
			break ;
		number *= 10;
		number += (str[i] - '0');
		++i;
	}
	return (sign * number);
}

size_t	get_time_now(void)
{
	t_time	time;

	if (gettimeofday(&time, NULL) == -1)
		error_message("[Error] Time fault\n", EXIT_FAILURE);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = get_time_now();
	while (get_time_now() - start < mls)
		usleep(500);
}
