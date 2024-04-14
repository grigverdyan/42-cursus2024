/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:50:47 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:50:48 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation_bonus.h"
#include "make_stack_bonus.h"
#include "utils_bonus.h"
#include "stack_actions_bonus.h"
#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	int		nums_count;
	int		*unordered;
	t_stack	stack_a;
	t_stack	stack_b;

	nums_count = check_args(argc, argv);
	init_stacks(&stack_a, &stack_b);
	unordered = get_nums(nums_count, argv);
	check_duplicates(unordered, nums_count);
	make_stack_a(&stack_a, unordered, nums_count);
	free(unordered);
	checker(&stack_a, &stack_b);
	return (0);
}
