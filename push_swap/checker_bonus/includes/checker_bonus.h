/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:36:30 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:37:19 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	int				value;

}	t_lst;

typedef struct s_stack
{
	t_lst	*head;
	t_lst	*tail;
	int		nodes;
}	t_stack;

void	checker(t_stack *st_a, t_stack *st_b);
int		check_inst(char *inst);
void	do_inst(char *inst, t_stack *st_a, t_stack *st_b);
void	is_sorted_stack(t_stack *st_a, t_stack *st_b);
void	sorted_exit(t_stack *st_a, t_stack *st_b, char *sms);

#endif	/* CHECKER_BONUS_H */
