/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:56:24 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:56:25 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "utils.h"

void	ft_free(int *unordered, int *sorted, char *sms)
{
	if (unordered != NULL)
		free(unordered);
	if (sorted != NULL)
		free(sorted);
	error_message(sms);
}

void	free_matrix(char **matrix, int size)
{
	size = size - 1;
	while (size >= 0)
	{
		free(matrix[size]);
		--size;
	}
	free(matrix);
}

void	free_and_exit(char **matrix, int size, char *sms)
{
	free_matrix(matrix, size);
	error_message(sms);
}

void	free_list_and_exit(t_stack *stack, int *arrays[], int i)
{
	int		j;
	t_lst	*temp;

	j = -1;
	if (arrays[0] != NULL)
		free(arrays[0]);
	if (arrays[1] != NULL)
		free(arrays[1]);
	while (++j < i)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	error_message("[MALLOC ERROR]: List allocation error!");
}

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
