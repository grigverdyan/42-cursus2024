/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:15:15 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/23 22:16:44 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

#include "fractal.h"

int	fr_mandelbrot(t_fractal *fract, t_complex *c);
int	fr_julia(t_fractal *fract, t_complex *c, int x, int y);

#endif /* FRACTALS_H */
