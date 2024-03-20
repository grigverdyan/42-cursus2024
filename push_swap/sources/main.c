#include "push_swap.h"
#include "parse_arguments.h"
#include "bubble_sort.h"
#include "make_stack.h"
#include "utils.h"
#include "stack_actions.h"
#include "sortings.h"
#include "butterfly.h"

int	main(int argc, char **argv)
{
	int		nums_count;
	int		*unordered;
	int		*sorted;
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack_b(&stack_b);
	sorted = NULL;
	unordered = NULL;
	nums_count = check_args(argc, argv, unordered);
	// unordered = get_nums(nums_count, argv);
	check_duplicates(unordered, nums_count);
	if (!is_sorted(unordered, nums_count))
		ft_free(unordered, sorted, "");
	sorted = copy_into_sorted(unordered, nums_count);
	if (nums_count == 2)
		double_sort(unordered, sorted);
	else if (nums_count >= 3)
	{
		make_stack_a(&stack_a, unordered, sorted, nums_count);
		if (nums_count >= 3 && nums_count <= 5)
			forbbiden_sorting(nums_count, &stack_a, &stack_b);
		else
			butterfly_algo(&stack_a, &stack_b, nums_count);
	}
	free_stacks_and_arrays(&stack_a, &stack_b, unordered, sorted);
	return (0);
}
