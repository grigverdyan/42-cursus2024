/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:46:12 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/21 21:17:09 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

int	side_len(int count);
int	is_valid_str(char *s);
int	*map_size(char *str, int *n);
int	not_greater_than_n(int *sides, int n);
int	*fill_sides(char *str, int count, int *n);

#endif
