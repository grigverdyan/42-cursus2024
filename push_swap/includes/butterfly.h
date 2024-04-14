/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:14 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:54:16 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTERFLY_H
# define BUTTERFLY_H

# include "push_swap.h"

void	butterfly_algo(t_stack *st_a, t_stack *st_b, int size);
void	make_butterfly(t_stack *st_a, t_stack *st_b, int chunk);
int		generate_chunk(int size);
void	sort_stack(t_stack *st_a, t_stack *st_b);
void	find_max_and_push_a(t_lst *lst, t_stack *stack_b, int size);
void	find_max_and_push_b(t_lst *lst, t_stack *stack_a, int size);

#endif
