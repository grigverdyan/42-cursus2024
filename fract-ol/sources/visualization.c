/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:00:27 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/23 22:18:43 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualization.h"
#include "fractals.h"

void	visualization(t_engine *engine)
{
	static t_complex	c;
	t_fractal			*fract;
	int					iter;
	int					x;
	int					y;

	x = -1;
	fract = &engine->fractal;
	mlx_clear_window(engine->mlx, engine->window);
	while (++x < WIN_SIZE)
	{
		y = -1;
		if (fract->type != Julia)
			c.re = (x / fract->zoom) + fract->offset_x;
		while (++y < WIN_SIZE)
		{
			iter = calc_fractal(fract, &c, x, y);
			set_pixel_color(engine, x, y, (iter * engine->fractal.color));
		}
	}
	mlx_put_image_to_window(engine->mlx, engine->window, engine->image.p_img, 0, 0);
}

void	set_pixel_color(t_engine *engine, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
	offset = (y * engine->image.line_len) + ((engin:e->image.pixel_bits / 8) * x);
	*(unsigned int *)(engine->image.p_addr + offset) = color;
}

int	calc_fractal(t_fractal* fract, t_complex* c, int x, int y)
{
	int	iter = 0;
	(void)x;
	if (fract->type != Julia)
		c->im = (y / fract->zoom) + fract->offset_y;
	else if (!fract->lock)
		c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == Mandelbrot)
		iter = fr_mandelbrot(fract, c);
	else if (fract->type == Julia)
		iter = fr_julia(fract, c, x, y);	
	return (iter);
}

