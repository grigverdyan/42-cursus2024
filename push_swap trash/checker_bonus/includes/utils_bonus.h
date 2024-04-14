/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:26:28 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:26:30 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "push_swap_bonus.h"

void	init_stacks(t_stack *st_a, t_stack *st_b);
void	free_inst_list(int i, char **list);
void	error_message(char *sms);
void	free_matrix(char **matrix, int size);
int		get_matrix_size(char **matrix);
void	free_and_exit(char **matrix, int size, char *sms);
void	ft_free(int *unordered, int *sorted, char *sms);
void	free_list_and_exit(t_stack *stack, int *unordered, int i);
int		is_sorted(int *unordered, int size);
void	free_stacks_and_arrays(t_stack *st_a, t_stack *st_b, int *a1, int *a2);
void	free_stacks(t_stack *st_a, t_stack *st_b);

#endif   /* UTILS_BONUS_H */
