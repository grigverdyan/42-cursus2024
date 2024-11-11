/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:51:58 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 22:52:25 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTIONS_H
# define PRINT_FUNCTIONS_H

# include "utils.h"
# include <unistd.h>
# include <stdlib.h>

int		find_translation(char *num, int len, t_line *dict);
void	print_matrix(char **mat);
void	print_dict(t_line *dict);
void	print_number(char *num, int len, t_line *dict);

#endif
