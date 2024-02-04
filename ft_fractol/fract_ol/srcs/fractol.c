/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:52:18 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/06 19:59:17 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	parsing(argc, argv, &fractal);
	start_fractal(&fractal, WIN_SIZE / 2, WIN_SIZE / 2);
	mlx_key_hook(fractal.win, hookers, &fractal);
	mlx_mouse_hook(fractal.win, mouse_hookers, &fractal);
	mlx_hook(fractal.win, 17, 0, red_cross_hookers, &fractal);
	mlx_hook(fractal.win, 6, 1L << 6, mousemove_hookers, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}

void	start_fractal(t_fractal *fractal, double x, double y)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (fractal->fractal == MANDELBROT)
		mandelbrot_set(fractal, x, y);
	else if (fractal->fractal == JULIA)
		julia_set(fractal, x, y);
	else if (fractal->fractal == BURNINGSHIP)
		burning_ship_set(fractal, x, y);
	else if (fractal->fractal == BUFFALO)
		bufallo_set(fractal, x, y);
	else if (fractal->fractal == HEARTMANDELBROT)
		heart_mandelbrot_set(fractal, x, y);
	else if (fractal->fractal == CELTICMANDELBROT)
		celtic_mandelbrot_set(fractal, x, y);
	else if (fractal->fractal == TRICORN)
		tricorn_set(fractal, x, y);
	else if (fractal->fractal == BURNINGSHIPFIFTH)
		burning_ship_fifth_set(fractal, x, y);
	else if (fractal->fractal == PERPENDICULARBURNINGSHIP)
		perpendicular_burning_ship_set(fractal, x, y);
	else if (fractal->fractal == CELTICMANDELBAR)
		celtic_mandelbar_set(fractal, x, y);
}
