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

static double	box_fold(double z)
{
	if (z > 1)
		z = 2 - z;
	else if (z < -1)
		z = -2 - z;
	return (z);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	fr_mandelbox(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	double		mag;
	int			i;

	i = -1;
	mag = 0;
	z.re = c->re;
	z.im = c->im;
	while ((sqrt(mag) < 2) && (++i < fract->iterations))
	{
		z.re = FIXED_RADIUS * box_fold(z.re);
		z.im = FIXED_RADIUS * box_fold(z.im);
		mag = sqrt(z.re * z.re + z.im * z.im);
		z.re = z.re * SCALE * ball_fold(MINIMUM_RADIUS, mag) + c->re;
		z.im = z.im * SCALE * ball_fold(MINIMUM_RADIUS, mag) + c->im;
	}
	return (i);
}

int	fr_heart_mandelbrot(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	int			iter;

	z.im = 0;
	z.re = 0;
	iter = -1;
	while ((z.re * z.re + z.im * z.im) <= 4 && ++iter < fract->iterations)
	{
		if (z.re < 0)
			z.im = -1.0 * (z.re) * z.im * 2.0 + c->im;
		else
			z.im = z.re * z.im * 2.0 + c->im;
		z.re = z.re * z.re - z.im * z.im + c->re;
	}
	return (iter);
}
