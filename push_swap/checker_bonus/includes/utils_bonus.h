/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:38:43 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:39:05 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "checker_bonus.h"

void	init_stacks(t_stack *st_a, t_stack *st_b);
void	error_message(char *sms);
int		get_matrix_size(char **matrix);
int		is_sorted(int *unordered, int size);
int		*get_nums(int nums_count, char **argv);

#endif   /* UTILS_BONUS_H */
