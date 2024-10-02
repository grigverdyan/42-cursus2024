/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:12:42 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:12:43 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**preprocessing(char *inpt)
{
	if (!inpt)
		free_and_exit(0);
	if (ft_strlen(inpt) == 0)
		return (NULL);
	add_history(inpt);
	if (!is_balanced(inpt))
		return (error("unmatched parentheses", 258));
	if (!check_quotes(inpt))
		return (error("unmatched quotes", 1));
	if (!logic_or_pipe(inpt))
		return (error("unsupported instruction combination", 1));
	if (!invalid_logic_operator(inpt))
		return (error("invalid token", 1));
	if (!invalid_start_and_end(inpt))
		return (error("invalid starting/ending token", 1));
	return (smart_split(inpt));
}
