/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkrivogo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:19:36 by vkrivogo          #+#    #+#             */
/*   Updated: 2023/10/29 21:47:23 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "print_functions.h"

int	find_translation(char *num, int len, t_line *dict)
{
	char	*split_num;
	int		idx;
	int		flag_print;

	split_num = ft_strndup(num, len);
	flag_print = 0;
	idx = 0;
	while (idx < NUM_COUNT)
	{
		if (ft_strcmp(split_num, dict[idx].key) == 0)
		{
			ft_putstr(dict[idx].value);
			flag_print = 1;
			break ;
		}
		++idx;
	}
	free(split_num);
	return (flag_print);
}

void	print_matrix(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
	{
		ft_putstr(mat[i]);
		write (1, "\n", 1);
	}
}

void	print_dict(t_line *dict)
{
	int	i;

	i = -1;
	while (++i < NUM_COUNT)
	{
		ft_putstr("\n\nKey : ");
		ft_putstr(dict[i].key);
		ft_putstr("\nValue : ");
		ft_putstr(dict[i].value);
		++i;
	}
}
