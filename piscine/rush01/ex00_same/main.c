/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:19:52 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/22 19:23:43 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "validation.h"
#include "solution.h"

int	main(int argc, char **argv)
{
	int	*arr_sides;
	int	n;

	if (argc == 2)
	{
		if (!is_valid_str(argv[1]))
			return (ft_exit("Error\n"));
		else
		{
			arr_sides = map_size(argv[1], &n);
			if (arr_sides == NULL || !not_greater_than_n(arr_sides, n))
				return (ft_exit("Error\n"));
			solver(arr_sides, n);
		}
	}
	else
		return (ft_exit("Error\n"));
	return (0);
}
