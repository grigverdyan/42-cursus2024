/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:39:16 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/14 18:39:42 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_BONUS_H
# define VALIDATION_BONUS_H

# include "checker_bonus.h"

int		check_args(int argc, char **argv);
int		get_nums_count(char **argv);
void	check_num(char *num, char **temp, int *nums_count);
void	check_num1(char *num, char **temp);
void	check_duplicates(int *unordered, int size);

#endif   /* VALIDATION_BONUS_H */
