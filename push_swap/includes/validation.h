/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:32 by grverdya          #+#    #+#             */
/*   Updated: 2024/03/20 20:55:41 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "libft.h"

int		check_args(int argc, char **argv);
int		get_nums_count(char **argv);
void	check_num(char *num, char **temp, int *nums_count);
void	check_num1(char *num, char **temp);
void	check_duplicates(int *unordered, int size);
int		*copy_into_sorted(int *arr, int size);
int		*get_nums(int nums_count, char **argv);
int		is_sorted(int *unordered, int size);

#endif   /* VALIDATION_H */
