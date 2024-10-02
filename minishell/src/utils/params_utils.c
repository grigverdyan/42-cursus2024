/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:17 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:18 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	text_len(t_string *text)
{
	int	len;

	len = -1;
	if (!text)
		return (0);
	while (text[++len])
		;
	return (len);
}

t_string	*get_full_param(t_string command_name, t_string *params)
{
	int			len;
	int			i;
	t_string	*full_params;

	i = -1;
	len = text_len(params);
	full_params = malloc(sizeof(t_string) * (len + 2));
	full_params[0] = ft_strdup(command_name);
	while (params[++i])
		full_params[i + 1] = ft_strdup(params[i]);
	full_params[i + 1] = NULL;
	return (full_params);
}

int	is_token(char ch)
{
	return (contains("()<>|&", ch));
}
