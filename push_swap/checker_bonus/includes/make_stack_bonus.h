/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:38:13 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:38:17 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STACK_BONUS_H
# define MAKE_STACK_BONUS_H

# include "checker_bonus.h"

int		*get_nums(int nums_count, char **argv);
void	make_stack_a(t_stack *stack, int *unordered, int size);
t_lst	*make_lst(t_stack *stack, int *unordered, int i);

#endif   /* MAKE_STACK_BONUS_H */
