/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:19:11 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/23 22:20:41 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

#include "fractal.h"

void	change_color(int key, t_engine *engine);
void	change_view(int key, t_engine *engine);
void	change_fractal(int key, t_engine *engine);

#endif /* GRAPHIC_H */
