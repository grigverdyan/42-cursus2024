/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:12:34 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 22:49:07 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "allocation.h"
#include "utils.h"

int	free_arr(char *arr, int ret)
{
	free(arr);
	return (ret);
}

int	free_arrs(char *arr1, char *arr2, int ret)
{
	free(arr1);
	free(arr2);
	return (ret);
}

void	free_matrix(char **m)
{
	int	i;

	i = -1;
	while (++i < NUM_COUNT)
	{
		free(m[i]);
	}
	free(m);
}

void	free_dict(t_line *dict)
{
	int	i;

	i = -1;
	while (++i < NUM_COUNT)
	{
		free_arrs(dict[i].key, dict[i].value, 1);
	}
	free(dict);
}
