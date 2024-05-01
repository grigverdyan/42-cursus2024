/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:06:02 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 19:06:19 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup_bonus.h"
#include "utils_bonus.h"

void	error_message(char *sms)
{
	write(2, sms, ft_strlen(sms));
	exit(EXIT_FAILURE);
}

int	get_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		++i;
	return (i + 1);
}

int	is_sorted(int *unordered, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		ft_free(unordered, NULL, NULL);
	while (++i < size)
	{
		if (unordered[i] <= unordered[i - 1])
			return (1);
	}
	return (0);
}

int	*get_nums(int nums_count, char **argv)
{
	int		*nums;
	char	**temp;
	int		indx[3];

	indx[0] = 0;
	indx[2] = -1;
	nums = (int *)malloc(sizeof(int) * nums_count);
	if (!nums)
		error_message("Error\n");
	while (argv[++indx[0]])
	{
		temp = ft_split(argv[indx[0]], ' ');
		if (!temp)
			error_message("Error\n");
		else if (temp[0] == NULL)
			free_matrix(temp, 1);
		else
		{
			indx[1] = -1;
			while (temp[++indx[1]])
				nums[++indx[2]] = ft_atoi(temp[indx[1]]);
			free_matrix(temp, get_matrix_size(temp));
		}
	}
	return (nums);
}
