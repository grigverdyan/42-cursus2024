/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:49:31 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:49:32 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup_bonus.h"

void	free_stacks_and_arrays(t_stack *st_a, t_stack *st_b, int *a1, int *a2)
{
	t_lst	*temp;
	int		i;

	i = -1;
	while (++i < st_a->nodes)
	{
		temp = st_a->head;
		st_a->head = st_a->head->next;
		free(temp);
	}
	if (st_b->head != NULL)
	{
		i = -1;
		while (++i < st_a->nodes)
		{
			temp = st_a->head;
			st_a->head = st_a->head->next;
			free(temp);
		}
	}
	if (a1 != NULL)
		free(a1);
	if (a1 != NULL)
		free(a2);
}

void	free_stacks(t_stack *st_a, t_stack *st_b)
{
	int		i;
	t_lst	*temp;

	if (st_a->head != NULL)
	{
		i = -1;
		while (++i < st_a->nodes)
		{
			temp = st_a->head;
			st_a->head = st_a->head->next;
			free(temp);
		}
	}
	if (st_b->head != NULL)
	{
		i = -1;
		while (++i < st_b->nodes)
		{
			temp = st_b->head;
			st_b->head = st_b->head->next;
			free(temp);
		}
	}
}
