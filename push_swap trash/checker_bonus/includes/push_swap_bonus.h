/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:26:33 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:26:34 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_lst
{
	int				value;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_stack
{
	t_lst	*head;
	t_lst	*tail;
	int		nodes;
}	t_stack;

#endif   /* PUSH_SWAP_BONUS_H */
