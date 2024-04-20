/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:17:46 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/20 20:36:00 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx.h"
#include "libft.h"

#include <stdlib.h>

enum e_Fractal	get_fractal_type(char* str)
{
	char*	type;
	int		len;

	if (str)
	{
		type = ft_strlowcase(str);
		len = ft_strlen(type);		
		if (ft_strncmp(type, "mandelbrot", len) == 0)
			return (Mandelbrot);
		if (ft_strncmp(type, "julia", len) == 0)
			return (Julia);
	}
	return None;
}

void	set_fractal(t_engine* engine, char* str)
{
	engine->fractal.type = get_fractal_type(str);
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.zoom = WIN_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.iterations = MIN_ITERATIONS;
}

void	start_engine(t_engine* engine, char* str)
{
	set_fractal(engine, str);
	print(ft_itoa(engine->fractal.type));
	if (engine->fractal.type == None)
	{
		help();
	}
	engine->mlx = mlx_init();
	if (!engine->mlx)
		throw_error("[ERROR] : MiniLibX initialization error!");
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	if (!engine->window)
		throw_error("[ERROR] : MiniLibX window creation error!");
	engine->image.p_img = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->image.p_img)
		throw_error("[ERROR] : MiniLibX image creation error!");	
	engine->image.p_addr = mlx_get_data_addr(engine->image.p_img, &engine->image.pixel_bits, &engine->image.line_len, &engine->image.endian);
	if (!engine->image.p_addr)
		throw_error("[ERROR] : MiniLibX image creation error!");
}

int	calc_mandelbrot(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}

int	calc_fractal(t_fractal* fract, t_complex* c, int x, int y)
{
	int	iter = 0;
	(void)x;
	if (fract->type != Julia)
		c->im = (y / fract->zoom) + fract->offset_y;
//	else if (!fract->is_julia_lock)
		c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == Mandelbrot)
		iter = calc_mandelbrot(fract, c);
	return (iter);
}

void	set_pixel_color(t_engine *engine, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
	offset = (y * engine->image.line_len) + ((engine->image.pixel_bits / 8) * x);
	*(unsigned int *)(engine->image.p_addr + offset) = color;
}


void	draw_fractal(t_engine *engine)
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

int	main(int argc, char** argv)
{
	t_engine	engine;

	if (argc == 2)
	{
		start_engine(&engine, argv[1]);
		mlx_loop(engine.mlx);
	}
	else
	{
		help();
	}
	return (0);
}


