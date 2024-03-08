/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:23:01 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:24:15 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_H
# define CHECK_ARGS_H

# include "libft.h"

int		check_args(int argc, char **argv);
int		get_nums_count(char **argv);
void	check_num(char *num, char **temp, int *nums_count);
void	check_num1(char *num, char **temp);
void	check_duplicates(int *unordered, int size);

#endif   /* CHECK_ARGS_H */
