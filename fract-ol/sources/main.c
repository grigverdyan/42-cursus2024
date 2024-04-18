/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:17:46 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/17 21:35:23 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx.h"

void	start_engine(t_engine* engine, char* str)
{
	engine->mlx = mlx_init();

	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
}

int	main(int argc, char** argv)
{
	t_engine	engine;

	start_engine(&engine, argv[1]);

	return (0);
}
void	set_default_parameters(t_engine* engine, e_Fractal type)
{
	engine->fractal.type = type;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.zoom = WIN_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.iterations = MIN_ITERATIONS;
}

