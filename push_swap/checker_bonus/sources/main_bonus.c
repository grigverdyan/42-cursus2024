/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:27:29 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:27:30 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "check_args_bonus.h"
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

	init_stacks(&stack_a, &stack_b);
	nums_count = check_args(argc, argv);
	unordered = get_nums(nums_count, argv);
	check_duplicates(unordered, nums_count);
	make_stack_a(&stack_a, unordered, nums_count);
	free(unordered);
	checker(&stack_a, &stack_b);
	return (0);
}
