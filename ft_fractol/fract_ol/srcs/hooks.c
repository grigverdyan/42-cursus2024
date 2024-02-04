/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:48:53 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/07 22:25:05 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	hookers(int key, t_fractal *fractal)
{
	if (key == KEY_ESC)
	{
		mlx_clear_window(fractal->mlx, fractal->win);
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
		exit(1);
	}
	else if ((key >= KEY_ONE && key <= KEY_NINE) || key == KEY_ZERO || \
		key == KEY_SEVEN || key == KEY_EIGHT)
		change_fractal(key, fractal);
	else if (key == UP || key == RIGHT || key == DOWN || key == LEFT)
		change_movement(key, fractal);
	else if (key == KEYPAD_ZERO)
		init_variables(fractal);
	else if (key == KEY_L)
		fractal->lock *= -1;
	else if ((key >= KEY_A && key <= KEY_T) || key == KEY_Y)
		change_color(key, fractal);
	else
		return (0);
	start_fractal(fractal, WIN_SIZE / 2, WIN_SIZE / 2);
	return (0);
}

int	mousemove_hookers(int x, int y, t_fractal *fractal)
{
	if (fractal->fractal != JULIA)
		return (0);
	if (fractal->lock == 1)
	{
		fractal->curr_x = convert_range(x, fractal->x_upper, fractal->x_lower);
		fractal->curr_y = convert_range(y, fractal->y_upper, fractal->y_lower);
		mlx_clear_window(fractal->mlx, fractal->win);
		julia_set(fractal, WIN_SIZE / 2, WIN_SIZE / 2);
	}
	return (0);
}

int	mouse_hookers(int key, int x, int y, t_fractal *fractal)
{
	if (fractal->fractal != JULIA && fractal->lock != 1)
		return (0);
	if (key == MOUSE_SCRL_UP)
		fractal->zoom_const *= 2;
	else if (key == MOUSE_SCRL_DOWN)
		fractal->zoom_const /= 2;
	else
		return (0);
	start_fractal(fractal, x, y);
	return (0);
}

int	red_cross_hookers(void *param)
{
	(void)param;
	exit(0);
}

void	change_movement(int key, t_fractal *fractal)
{
	if (fractal->fractal != JULIA && fractal->lock != 1)
		return ;
	if (key == UP)
	{
		fractal->y_lower -= 0.5 / fractal->zoom_const;
		fractal->y_upper -= 0.5 / fractal->zoom_const;
	}
	else if (key == RIGHT)
	{
		fractal->x_lower += 0.5 / fractal->zoom_const;
		fractal->x_upper += 0.5 / fractal->zoom_const;
	}
	else if (key == DOWN)
	{
		fractal->y_lower += 0.5 / fractal->zoom_const;
		fractal->y_upper += 0.5 / fractal->zoom_const;
	}
	else if (key == LEFT)
	{
		fractal->x_lower -= 0.5 / fractal->zoom_const;
		fractal->x_upper -= 0.5 / fractal->zoom_const;
	}
}
