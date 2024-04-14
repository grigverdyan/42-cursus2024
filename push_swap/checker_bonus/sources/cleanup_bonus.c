/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:49:23 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:49:26 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup_bonus.h"
#include "utils_bonus.h"

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

void	ft_free(int *unordered, int *sorted, char *sms)
{
	if (unordered != NULL)
		free(unordered);
	if (sorted != NULL)
		free(sorted);
	error_message(sms);
}

void	free_inst_list(int i, char **list)
{
	while (i-- >= 0)
		free(list[i]);
	free(list);
}

void	free_list_and_exit(t_stack *stack, int *unordered, int i)
{
	int		j;
	t_lst	*temp;

	j = -1;
	if (unordered != NULL)
		free(unordered);
	while (++j < i)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	error_message("Error\n");
}
