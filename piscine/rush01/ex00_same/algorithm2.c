/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:55:25 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 20:58:00 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithm.h"

int	dealloc_lines(t_lines *l, int ret_type)
{
	free(l->line_x);
	free(l->line_y);
	return (ret_type);
}

void	change_position(int	*row, int *col, int n, int when)
{
	if (when == 1)
	{
		if (*col == n)
		{
			*row += 1;
			*col = 1;
		}
		else
			*col += 1;
	}
	else
	{
		if (*col == 1)
		{
			*row -= 1;
			*col = n;
		}
		else
			*col -= 1;
	}
}
