/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:52:10 by tsas              #+#    #+#             */
/*   Updated: 2022/07/07 21:40:58 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_boundaries(t_fractal *fractal, int x, int y, double spec)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = fractal->x_lower;
	fractal->x_lower -= convert_range(x, 2.0, -2.0) / fractal->zoom_const;
	fractal->x_upper += convert_range(WIN_SIZE - x, 2.0, -2.0) / \
		fractal->zoom_const;
	tmp_y = fractal->y_lower;
	fractal->y_lower -= convert_range(y, 2.0, -2.0) / fractal->zoom_const;
	fractal->y_upper += convert_range(WIN_SIZE - y, 2.0, -2.0) / \
		fractal->zoom_const;
	tmp_x = fractal->x_lower;
	fractal->x_lower = convert_range(x, fractal->x_upper, fractal->x_lower) - \
		spec / fractal->zoom_const;
	fractal->x_upper = convert_range(x, fractal->x_upper, tmp_x) + \
		spec / fractal->zoom_const;
	tmp_y = fractal->y_lower;
	fractal->y_lower = convert_range(y, fractal->y_upper, fractal->y_lower) - \
		spec / fractal->zoom_const;
	fractal->y_upper = convert_range(y, fractal->y_upper, tmp_y) + \
		spec / fractal->zoom_const;
}

void	change_pixel_color(t_fractal *fractal, int x, int y, int color)
{
	if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
	*(unsigned int*) \
	(fractal->img.data_addr + \
	(x * fractal->img.size_line + y * (fractal->img.bits_per_pixel / 8))) \
	= color;
}

double	convert_range(double old_value, double new_max, double new_min)
{
	return ((((old_value - 0.0) * (new_max - new_min)) / (WIN_SIZE - 0.0)) + \
		new_min);
}

void	change_variables(t_fractal *fractal)
{
	fractal->zoom_const = 1;
	fractal->color = 0x040000;
	fractal->x_lower = -2.0;
	fractal->x_upper = 2.0;
	fractal->y_lower = -2.0;
	fractal->y_upper = 2.0;
}
