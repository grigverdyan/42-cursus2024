#ifndef BUBBLE_SORT_H
# define BUBBLE_SORT_H

# include "ft_printf.h"
# include "push_swap.h"

void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
void	print_array(int *arr, int size);
int		*copy_into_sorted(int *arr, int size);

#endif   /* BUBBLE_SORT_H */
