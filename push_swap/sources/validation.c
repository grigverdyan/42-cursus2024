/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:56:38 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:57:32 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "utils.h"
#include "cleanup.h"

int	check_args(int argc, char **argv)
{
	int	nums_count;

	nums_count = 0;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	nums_count = get_nums_count(argv);
	if (nums_count == 0)
		error_message("Error\n");
	return (nums_count);
}

int	get_nums_count(char **argv)
{
	int		i;
	int		j;
	char	**temp;
	int		nums_count;

	i = 0;
	nums_count = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			error_message("Error\n");
		else if (temp[0] == NULL)
			free_matrix(temp, 1);
		else
		{
			j = -1;
			while (temp[++j])
				check_num(temp[j], temp, &nums_count);
			free_matrix(temp, get_matrix_size(temp));
		}
	}
	return (nums_count);
}

void	check_num(char *num, char **temp, int *nums_count)
{
	int	i;

	i = 0;
	*nums_count += 1;
	if (ft_isdigit(num[0]) != 1 && num[0] != '+' && num[0] != '-')
	{
		free_and_exit(temp, get_matrix_size(temp), "Error\n");
	}
	while (num[++i])
	{
		if (ft_isdigit(num[i]) != 1)
		{
			free_and_exit(temp, get_matrix_size(temp), "Error\n");
		}
	}
	check_num1(num, temp);
}

void	check_num1(char *num, char **temp)
{
	int	len;
	int	size;

	len = ft_strlen(num);
	size = get_matrix_size(temp);
	if ((num[0] == '+' || num[0] == '-') && num[1] == '0')
		free_and_exit(temp, size, "Error\n");
	else if (num[0] == '0' && num[1] != '\0')
		free_and_exit(temp, size, "Error\n");
	else if (num[0] == '-' && num[1] == '\0')
		free_and_exit(temp, size, "Error\n");
	else if (num[0] == '+' && num[1] == '\0')
		free_and_exit(temp, size, "Error\n");
	else if (len < 10)
		return ;
	else if (((num[0] == '+' || num[0] == '-') && len > 11)
		|| (ft_isdigit(num[0]) == 1 && len > 10))
		free_and_exit(temp, size, "Error\n");
	else if (num[0] == '+' && (ft_strncmp(num, "+2147483647", len) > 0))
		free_and_exit(temp, size, "Error\n");
	else if (num[0] == '-' && (ft_strncmp(num, "-2147483648", len) > 0))
		free_and_exit(temp, size, "Error\n");
	else if (ft_strncmp(num, "2147483647", len) > 0)
		free_and_exit(temp, size, "Error\n");
}
