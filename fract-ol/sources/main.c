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
#include "utils.h"
#include "events.h"
#include "keys.h"

#include <stdlib.h>
void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x300000;
	else if (key == KEY_W)
		engine->fractal.color += 0x030000;
	else if (key == KEY_E)
		engine->fractal.color += 0x003000;
	else if (key == KEY_R)
		engine->fractal.color += 0x000300;
	else if (key == KEY_T)
		engine->fractal.color += 0x000030;
	else if (key == KEY_Y)
		engine->fractal.color += 0x000003;
	else if (key == KEY_A)
		engine->fractal.color -= 0x300000;
	else if (key == KEY_S)
		engine->fractal.color -= 0x030000;
	else if (key == KEY_D)
		engine->fractal.color -= 0x003000;
	else if (key == KEY_F)
		engine->fractal.color -= 0x000300;
	else if (key == KEY_G)
		engine->fractal.color -= 0x000030;
	else if (key == KEY_H)
		engine->fractal.color -= 0x000003;
}

void	change_view(int key, t_engine *engine)
{
	t_fractal	*fractal;

	fractal = &engine->fractal;
	if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
}



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
	engine->fractal.lock = 0;
}

void	change_fractal(int key, t_engine *engine)
{
	set_fractal(engine, "mandelbrot");
	if (key == KEY_TWO)
		engine->fractal.type = Julia;
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
	engine->image.p_img = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	if (!engine->window || !engine->image.p_img)
	{
		mlx_destroy_window(engine->mlx, engine->window);
		mlx_destroy_image(engine->mlx, engine->image.p_img);
		throw_error("[ERROR] : MiniLibX image creation error!");	
	}
	engine->image.p_addr = mlx_get_data_addr(engine->image.p_img, &engine->image.pixel_bits, &engine->image.line_len, &engine->image.endian);
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


int	calc_julia(t_fractal *fract, t_complex *c, int x, int y)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = (x / fract->zoom) + fract->offset_x;
	z.im = (y / fract->zoom) + fract->offset_y;
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
	else if (!fract->lock)
		c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == Mandelbrot)
		iter = calc_mandelbrot(fract, c);
	else if (fract->type == Julia)
		iter = calc_julia(fract, c, x, y);	
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






int	on_mouse_hook(int key, int x, int y, t_engine *engine)
{
	t_fractal	*fr;

	fr = &engine->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
		if (fr->iterations < MAX_ITERATIONS)
			++fr->iterations;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
		if (fr->iterations > MIN_ITERATIONS)
			--fr->iterations;
	}
	visualization(engine);
	return (0);
}

int	on_key_hook(int key, t_engine *engine)
{
	if ((key >= KEY_Q && key <= KEY_Y) || (key >= KEY_A && key <= KEY_H))
		change_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		change_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FIVE)
		change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == Julia)
		engine->fractal.lock ^= 1;
//	else if (key == KEY_ZERO)
//		set_fractal(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		on_destroy(engine);
	visualization(engine);
	return (0);
}

int	on_mouse_move(int x, int y, t_engine *engine)
{
	if (!(engine->fractal.type == Julia) || engine->fractal.lock)
		return (0);
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	visualization(engine);
	return (0);
}





int	main(int argc, char** argv)
{
	t_engine	engine;

	if (argc == 2)
	{
		start_engine(&engine, argv[1]);
		visualization(&engine);
		mlx_key_hook(engine.window, on_key_hook, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook, &engine);
	mlx_hook(engine.window, 6, 1L << 6, on_mouse_move, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy, &engine);
		mlx_loop(engine.mlx);
	}
	else
	{
		help();
	}
	return (0);
}


