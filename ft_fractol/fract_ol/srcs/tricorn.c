/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:11:10 by tsas              #+#    #+#             */
/*   Updated: 2022/07/07 21:16:11 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_tricorn_stable(t_complex c)
{
	t_complex	z;
	double		zimsqr;
	double		zresqr;
	int			iterations;

	z = init(0, 0);
	iterations = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && iterations < MAX_ITERATION)
	{
		zimsqr = z.im * z.im;
		zresqr = z.re * z.re;
		z.im = z.re * z.im * (-2.0) + c.im;
		z.re = zresqr - zimsqr + c.re;
		iterations++;
	}
	return (iterations);
}

void	tricorn_set(t_fractal *fractal, int x, int y)
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
			res = is_tricorn_stable(init(\
			convert_range(j, fractal->x_upper, fractal->x_lower), \
			convert_range(i, fractal->y_upper, fractal->y_lower)));
			change_pixel_color(fractal, i, j, res * fractal->color);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win,
		fractal->img.img_ptr, 0, 0);
}
