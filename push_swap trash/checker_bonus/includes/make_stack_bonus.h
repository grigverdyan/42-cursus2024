/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:26:35 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:26:36 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STACK_BONUS_H
# define MAKE_STACK_BONUS_H

# include "push_swap_bonus.h"

int		*get_nums(int nums_count, char **argv);
void	make_stack_a(t_stack *stack, int *unordered, int size);
t_lst	*make_lst(t_stack *stack, int *unordered, int i);

#endif   /* MAKE_STACK_BONUS_H */
