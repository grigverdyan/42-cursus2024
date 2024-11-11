/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkrivogo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:27:07 by vkrivogo          #+#    #+#             */
/*   Updated: 2023/10/29 21:34:58 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functions.h"

void	print_razryad(char first_digit, int num_zero, int space_q, t_line *dict)
{
	char	*num;
	int		idx;

	if (num_zero == 0)
		return ;
	num = malloc(num_zero + 1);
	num[0] = first_digit;
	idx = 0;
	while (idx < num_zero)
	{
		num[idx + 1] = '0';
		++idx;
	}
	if (space_q == 1)
		write(1, " ", 1);
	find_translation(num, num_zero + 1, dict);
	free(num);
}

void	print_two_digits(char *num, t_line *dict)
{
	if (*num == '0' && *(num + 1) == '0')
		return ;
	if (*num != '0' && find_translation(num, 2, dict) == 1)
		return ;
	if (*num == '0')
		find_translation(num + 1, 1, dict);
	else
	{
		print_razryad(*num, 1, 0, dict);
		write(1, "-", 1);
		find_translation(num + 1, 1, dict);
	}
}

void	print_three_digits(char *num, t_line *dict)
{
	if (*num != '0')
	{
		find_translation(num, 1, dict);
		print_razryad('1', 2, 1, dict);
		if (*(num + 1) != '0' || *(num + 2) != '0')
		{
			write(1, " and ", 5);
		}
	}
	print_two_digits(num + 1, dict);
}

void	print_number(char *num, int len, t_line *dict)
{
	int		idx;

	idx = 0;
	if (len % 3 != 0)
	{
		if (len % 3 == 2)
			print_two_digits(num, dict);
		else
			find_translation(num, 1, dict);
		print_razryad('1', ((len - idx) / 3) * 3, 1, dict);
		idx += len % 3;
	}
	while (num[idx])
	{
		if (num[idx] != '0' || num[idx + 1] != '0' || num[idx + 2] != '0')
		{
			if (idx > 0)
				write(1, ", ", 2);
			print_three_digits(num + idx, dict);
			print_razryad('1', ((len - (idx + 1)) / 3) * 3, 1, dict);
		}
		idx += 3;
	}
}
