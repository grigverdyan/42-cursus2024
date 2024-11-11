/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:04:56 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 22:49:18 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_H
# define ALLOCATION_H

# include "utils.h"

int		free_arr(char *arr, int ret);
int		free_arrs(char *arr1, char *arr2, int ret);
void	free_matrix(char **m);
void	free_dict(t_line *dict);

#endif 
