/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:01:15 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:32:33 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "ft_string.h"
#include "print_functions.h"

int	ft_exit(char *str, int ret_type)
{
	write(1, str, ft_strlen(str));
	return (ret_type);
}

char	*ft_isspace(char *str)
{
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
	{
		++str;
	}
	return (str);
}

char	*ft_atoi_string(char *str, int for_input)
{
	int		i;
	int		len;
	int		digit_idx;
	char	*number;

	str = ft_isspace(str);
	i = 0;
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (NULL);
	digit_idx = i;
	len = 0;
	while (str[i] >= '0' && str[i++] <= '9')
		++len;
	if (str[i] && for_input)
		return (NULL);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	i = -1;
	while (++i < len)
		number[i] = str[digit_idx++];
	number[i] = '\0';
	return (number);
}

char	**get_default_nums(void)
{
	char	**default_mat;

	default_mat = (char **) malloc(sizeof(char *) * NUM_COUNT);
	if (!default_mat)
		return (NULL);
	set_values(default_mat);
	return (default_mat);
}
