/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:01:41 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/08 21:19:12 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parsing(int argc, char **argv, t_fractal *fractal)
{
	if (argc != 2 || !which_fractal(fractal, argv[1]))
	{
		write(1, "\n", 1);
		write(1, "-------------------Let me help you!-------------------\n", 55);
		write(1, "Usage:  ./fractol [mandelbrot / julia / burning_ship /\n", 55);
		write(1, "                   buffalo /\n", 29);
		write(1, "                   heart_mandelbrot /\n", 38);
		write(1, "                   celtic_mandelbrot /\n", 39);
		write(1, "                   tricorn /\n", 29);
		write(1, "                   burning_ship_fifth /\n", 40);
		write(1, "                   perpendicular_burning_ship /\n", 48);
		write(1, "                   celtic_mandelbar]\n", 37);
		write(1, "\ne.g: ./fractol mandelbrot\n\n", 28);
		write(1, "-----------------------KEYBOARD-----------------------\n", 55);
		write(1, "\nPress ESC to close the window\n", 31);
		write(1, "Press one of [0-9] to move to another fractal\n", 46);
		write(1, "Press one of [Q-Y] keys to change the color of fractal\n", 55);
		write(1, "Press one of [A-H] keys to change the color of fractal\n", 55);
		write(1, "Press L to lock Julia's fractal\n", 32);
		write(1, "Press the arrow keys to change the viewpoint\n", 45);
		write(1, "Press Zero on the numpad to reset the fractal\n", 46);
		write(1, "Use mouse scroll to zoom in and out of the fractal\n\n", 52);
		exit(1);
	}
	init_mlx(fractal);
}

int	which_fractal(t_fractal *fractal, char *fractal_name)
{
	ft_strlower(fractal_name);
	if (!ft_strcmp(fractal_name, "mandelbrot"))
		fractal->fractal = MANDELBROT;
	else if (!ft_strcmp(fractal_name, "julia"))
		fractal->fractal = JULIA;
	else if (!ft_strcmp(fractal_name, "burning_ship"))
		fractal->fractal = BURNINGSHIP;
	else if (!ft_strcmp(fractal_name, "buffalo"))
		fractal->fractal = BUFFALO;
	else if (!ft_strcmp(fractal_name, "heart_mandelbrot"))
		fractal->fractal = HEARTMANDELBROT;
	else if (!ft_strcmp(fractal_name, "celtic_mandelbrot"))
		fractal->fractal = CELTICMANDELBROT;
	else if (!ft_strcmp(fractal_name, "tricorn"))
		fractal->fractal = TRICORN;
	else if (!ft_strcmp(fractal_name, "burning_ship_fifth"))
		fractal->fractal = BURNINGSHIPFIFTH;
	else if (!ft_strcmp(fractal_name, "perpendicular_burning_ship"))
		fractal->fractal = PERPENDICULARBURNINGSHIP;
	else if (!ft_strcmp(fractal_name, "celtic_mandelbar"))
		fractal->fractal = CELTICMANDELBAR;
	else
		return (0);
	return (1);
}

void	init_mlx(t_fractal *fractal)
{
	int	endian;
	int	size_line;
	int	bits_per_pixel;

	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		going_in_style("Error while initializing mlx");
	fractal->win = mlx_new_window(fractal->mlx, WIN_SIZE, WIN_SIZE, "*-*");
	if (!fractal->win)
		going_in_style("Error while creating window");
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIN_SIZE, WIN_SIZE);
	if (!fractal->img.img_ptr)
		going_in_style("Error while creating image");
	fractal->img.data_addr = mlx_get_data_addr(fractal->img.img_ptr,
			&bits_per_pixel, &size_line, &endian);
	fractal->img.bits_per_pixel = bits_per_pixel;
	fractal->img.size_line = size_line;
	fractal->img.endian = endian;
	init_variables(fractal);
	fractal->lock = 1;
}

void	init_variables(t_fractal *fractal)
{
	fractal->curr_x = 0;
	fractal->curr_y = 0;
	fractal->zoom_const = 1;
	fractal->zoom_const = 1;
	fractal->color = 0x040000;
	fractal->x_lower = -2.0;
	fractal->x_upper = 2.0;
	fractal->y_lower = -2.0;
	fractal->y_upper = 2.0;
}

void	change_fractal(int key, t_fractal *fractal)
{
	if (key == KEY_ONE)
		fractal->fractal = MANDELBROT;
	else if (key == KEY_TWO)
		fractal->fractal = JULIA;
	else if (key == KEY_THREE)
		fractal->fractal = BURNINGSHIP;
	else if (key == KEY_FOUR)
		fractal->fractal = BUFFALO;
	else if (key == KEY_FIVE)
		fractal->fractal = HEARTMANDELBROT;
	else if (key == KEY_SIX)
		fractal->fractal = CELTICMANDELBROT;
	else if (key == KEY_SEVEN)
		fractal->fractal = TRICORN;
	else if (key == KEY_EIGHT)
		fractal->fractal = BURNINGSHIPFIFTH;
	else if (key == KEY_NINE)
		fractal->fractal = PERPENDICULARBURNINGSHIP;
	else if (key == KEY_ZERO)
		fractal->fractal = CELTICMANDELBAR;
	change_variables(fractal);
}
