/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:26:13 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/07 21:16:47 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_julia_stable(t_complex z, double x, double y)
{
	double	zimsqr;
	double	zresqr;
	int		iterations;

	iterations = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && iterations < MAX_ITERATION)
	{
		zimsqr = z.im * z.im;
		zresqr = z.re * z.re;
		z.im = z.re * z.im * 2.0 + y;
		z.re = zresqr - zimsqr + x;
		iterations++;
	}
	return (iterations);
}

void	julia_set(t_fractal *fractal, int x, int y)
{
	int		i;
	int		j;
	int		res;

	i = -1;
	res = 0;
	change_boundaries(fractal, x, y, 2);
	while (++i < WIN_SIZE)
	{
		j = -1;
		while (++j < WIN_SIZE)
		{
			res = is_julia_stable(init(\
			convert_range(j, fractal->x_upper, fractal->x_lower), \
			convert_range(i, fractal->y_upper, fractal->y_lower)), \
			fractal->curr_x, fractal->curr_y);
			change_pixel_color(fractal, i, j, res * fractal->color);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img_ptr, 0, 0);
}
