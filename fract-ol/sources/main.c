/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:17:46 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/18 22:32:49 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx.h"
#include "libft.h"

void	throw_error(const char* message)
{
	ft_
}

/*
enum e_Fractal	get_fractal_type(char* str)
{
	char*	type;
	int		len;

	if (str)
	{
		type = ft_tolowercase(str);
		len = ft_strlen(type);		
		if (ft_strncmp(type, "mandelbrot", len) == 0)
			return (Mandelbrot);
		if (ft_strncmp(type, "julia", len) == 0)
			return (Julia);
	}
	return None;
}
*/
void	set_fractal(t_engine* engine, char* str)
{
	//engine->fractal.type = get_fractal_type(str);
	(void)str;
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
	if (engine->fractal.type == None)
	{
		// help();
	}
	engine->mlx = mlx_init();

	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
//	engine->image.p_img = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);

//	engine->image.p_addr = mlx_get_data_addr(engine->image.p_img, &engine->image.pixel_bits, &engine->image.line_len, &engine->image.endian);
}

int	main(int argc, char** argv)
{
	t_engine	engine;

	if (argc == 2)
	{
		//
		start_engine(&engine, argv[1]);
	}
	else
	{
		// help()
	}
	return (0);
}


