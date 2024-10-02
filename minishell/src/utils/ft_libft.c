/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:59 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:00 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long int	basic_atoi(const t_string str)
{
	int				sign;
	int				i;
	long long int	result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	return (result * sign);
}

t_string	ft_strtrim(const t_string str)
{
	int			start;
	int			end;
	int			i;
	t_string	trimmed;

	start = 0;
	i = -1;
	end = ft_strlen(str) - 1;
	while (str[start] == ' ')
		start++;
	while (str[end] == ' ')
		end--;
	if (start > end)
		return (NULL);
	trimmed = malloc(end - start + 1);
	while (++i <= end - start)
		trimmed[i] = str[start + i];
	trimmed[i] = 0;
	return (trimmed);
}
