/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:51 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:26:53 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(char **arguments)
{
	int		i;
	int		status;

	i = -1;
	status = 0;
	if (!arguments || !arguments[0])
		return (status);
	while (arguments[++i])
	{
		if (is_valid_export_key(arguments[i]))
			remove_with_key(g_data->env_list, arguments[i]);
		else
		{
			not_valid_identifier("unset", arguments[i]);
			status = 1;
		}
	}
	return (status);
}
