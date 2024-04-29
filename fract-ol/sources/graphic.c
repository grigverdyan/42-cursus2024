/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:06:36 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:12:23 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "keys.h"
#include "fractal.h"
#include "initialization.h"

void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x400000;
	else if (key == KEY_W)
		engine->fractal.color += 0x040000;
	else if (key == KEY_E)
		engine->fractal.color += 0x004000;
	else if (key == KEY_R)
		engine->fractal.color += 0x000400;
	else if (key == KEY_T)
		engine->fractal.color += 0x000040;
	else if (key == KEY_Y)
		engine->fractal.color += 0x000004;
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

void	change_fractal(int key, t_engine *engine)
{
	set_fractal(engine, "mandelbrot");
	if (key == KEY_TWO)
		engine->fractal.type = Julia;
	if (key == KEY_THREE)
		engine->fractal.type = Burning_Ship;
	if (key == KEY_FOUR)
		engine->fractal.type = Tricorn;
	if (key == KEY_FIVE)
		engine->fractal.type = Celtic_Mandelbar;
	if (key == KEY_SIX)
		engine->fractal.type = Mandelbox;
}
