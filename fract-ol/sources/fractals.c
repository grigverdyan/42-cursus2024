/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:08:52 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:11:41 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"
#include "fractal.h"
#include <math.h>

int	fr_mandelbrot(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	double		re_temp;
	int			iter;

	iter = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++iter < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (iter);
}

int	fr_julia(t_fractal *fract, t_complex *c, int x, int y)
{
	t_complex	z;
	double		re_temp;
	int			iter;

	iter = -1;
	z.re = (x / fract->zoom) + fract->offset_x;
	z.im = (y / fract->zoom) + fract->offset_y;
	while ((z.re * z.re + z.im * z.im) < 4 && ++iter < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (iter);
}

int	fr_burning_ship(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	double		re_temp;
	int			iter;

	iter = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++iter < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = fabs(2 * z.re * z.im) + c->im;
		z.re = fabs(re_temp);
	}
	return (iter);
}

int	fr_tricorn(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	double		re_temp;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = -2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}

int	fr_celtic_mandelbar(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	double		re_temp;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im;
		z.im = -2 * z.re * z.im + c->im;
		if (re_temp < 0)
			re_temp *= -1;
		z.re = re_temp + c->re;
	}
	return (i);
}
