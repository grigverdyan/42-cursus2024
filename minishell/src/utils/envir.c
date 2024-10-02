/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:15:57 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:15:59 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_string	get_env_row(t_node *node)
{
	t_string	new_row;
	t_string	temp;

	temp = ft_strdup(node->key);
	new_row = ft_strjoin(temp, "=");
	free(temp);
	temp = new_row;
	new_row = ft_strjoin(temp, node->value);
	free(temp);
	return (new_row);
}

int	get_env_count(void)
{
	int		count;
	t_node	*current;

	current = g_data->env_list->head;
	count = 0;
	while (current)
	{
		if (current->value)
			count++;
		current = current->next;
	}
	return (count);
}

t_string	*get_envir(void)
{
	int			count;
	int			index;
	t_string	*result;
	t_node		*current;

	index = 0;
	current = g_data->env_list->head;
	count = get_env_count();
	result = malloc(sizeof(t_string) * (count + 1));
	while (current)
	{
		if (current->value)
		{
			result[index] = get_env_row(current);
			index++;
		}
		current = current->next;
	}
	result[index] = 0;
	return (result);
}
