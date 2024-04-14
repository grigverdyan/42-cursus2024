/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:37:44 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:37:49 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_BONUS_H
# define CLEANUP_BONUS_H

# include "checker_bonus.h"

void	ft_free(int *unordered, int *sorted, char *sms);
void	free_matrix(char **matrix, int size);
void	free_and_exit(char **matrix, int size, char *sms);
void	free_inst_list(int i, char **list);
void	free_list_and_exit(t_stack *stack, int *unordered, int i);
void	free_stacks_and_arrays(t_stack *st_a, t_stack *st_b, int *a1, int *a2);
void	free_stacks(t_stack *st_a, t_stack *st_b);

#endif /* CLEANUP_BONUS_H */
