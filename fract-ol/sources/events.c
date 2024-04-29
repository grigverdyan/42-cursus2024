/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:51:02 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:10:55 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "mlx.h"
#include "fractal.h"
#include "visualization.h"
#include "keys.h"
#include "graphic.h"

#include <stdlib.h>

int	on_destroy(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.p_img);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
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
