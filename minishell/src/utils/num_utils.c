/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:15 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:17 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	num_len(int number)
{
	int	len;

	len = 1;
	while (number / 10 > 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	error_int(char *msg, int code)
{
	ft_putstr_fd("minishell: syntax error near ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	g_data->last_status = code;
	return (1);
}
