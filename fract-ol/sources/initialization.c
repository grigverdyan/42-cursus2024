/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:03:08 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/23 22:15:06 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

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

