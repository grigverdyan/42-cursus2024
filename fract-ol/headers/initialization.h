/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:12:18 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/23 22:14:59 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

#include "fractal.h"

void			start_engine(t_engine* engine, char* str);
void			set_fractal(t_engine* engine, char* str);
enum e_Fractal	get_fractal_type(char* str);

#endif /* INITIALIZATION_H */
