#ifndef MAKE_STACK_H
# define MAKE_STACK_H

# include "push_swap.h"

void	make_stack_a(t_stack *stack, int *unordered, int *sorted, int size);
void	init_stack_b(t_stack *stack);
t_lst	*make_lst(t_stack *stack, int *arrays[], int size, int i);
int		find_index(int *arr, int value, int size);

#endif   /* MAKE_STACK_H */
