/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_fifth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:26:29 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/07 21:20:19 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_burning_ship_fifth_stable(t_complex c)
{
	t_complex	z;
	double		zimsqr;
	double		zresqr;
	double		zimzre;
	int			iterations;

	z = init(0, 0);
	iterations = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && iterations < MAX_ITERATION)
	{
		zimsqr = z.im * z.im * z.im * z.im;
		zresqr = z.re * z.re * z.re * z.re;
		zimzre = z.im * z.im * z.re * z.re;
		if (z.im < 0)
			z.im = z.im * (5.0 * zresqr - 10.0 * zimzre + zimsqr) + c.im;
		else
			z.im = -1.0 * z.im * (5.0 * zresqr - 10.0 * zimzre + zimsqr) + c.im;
		if (z.re < 0)
			z.re = -1.0 * z.re * (zresqr - 10.0 * zimzre + 5.0 * zimsqr) + c.re;
		else
			z.re = z.re * (zresqr - 10.0 * zimzre + 5.0 * zimsqr) + c.re;
		iterations++;
	}
	return (iterations);
}

void	burning_ship_fifth_set(t_fractal *fractal, int x, int y)
{
	int		i;
	int		j;
	int		res;

	i = -1;
	res = 0;
	change_boundaries(fractal, x, y, 2.0);
	while (++i < WIN_SIZE)
	{
		j = -1;
		while (++j < WIN_SIZE)
		{
			res = is_burning_ship_fifth_stable(init(\
			convert_range(j, fractal->x_upper, fractal->x_lower), \
			convert_range(i, fractal->y_upper, fractal->y_lower)));
			change_pixel_color(fractal, i, j, res * fractal->color);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img_ptr, 0, 0);
}
