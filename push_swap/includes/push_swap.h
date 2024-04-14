/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:55:04 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:55:06 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_lst
{
	int				value;
	int				index;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_stack
{
	t_lst	*head;
	t_lst	*tail;
	int		nodes;
}	t_stack;

#endif   /* PUSH_SWAP_H */
