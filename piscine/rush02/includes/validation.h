/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:58:51 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:23:46 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "utils.h"

int		get_fd(char *file);
int		check_params(char *file, char *number);
int		check_dict(int fd);
int		is_valid_line(char *line);
int		get_before_colon(char *str);
int		is_valid_num(char *num);
char	*get_num_str(char *line, int i);
int		is_valid_num(char *num);
t_line	*get_dict(int fd, int *ret);
int		fill_dict(t_line *dict, char *line, int i);

#endif
