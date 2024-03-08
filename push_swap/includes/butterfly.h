/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:22:54 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:24:16 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTERFLY_H
# define BUTTERFLY_H

# include "push_swap.h"

void	butterfly_algo(t_stack *st_a, t_stack *st_b, int size);
void	make_butterfly(t_stack *st_a, t_stack *st_b, int chunk);
int		generate_chunk(int size);
void	sort_stack(t_stack *st_a, t_stack *st_b);

#endif
