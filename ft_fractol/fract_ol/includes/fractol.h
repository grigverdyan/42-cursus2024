/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:44:30 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/08 20:59:46 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __linux__
#  define KEY_ESC 65307

#  define UP 65362
#  define RIGHT 65363
#  define DOWN 65364
#  define LEFT 65361

#  define KEYPAD_ZERO 65438

#  define KEY_ONE 49
#  define KEY_TWO 50
#  define KEY_THREE 51
#  define KEY_FOUR 52
#  define KEY_FIVE 53
#  define KEY_SIX 54
#  define KEY_SEVEN 55
#  define KEY_EIGHT 56
#  define KEY_NINE 57
#  define KEY_ZERO 48

#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_E 101
#  define KEY_R 114
#  define KEY_T 116
#  define KEY_Y 121

#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_F 102
#  define KEY_G 103
#  define KEY_H 104

#  define KEY_L 108

#  define MOUSE_LEFT_CLK 1
#  define MOUSE_SCRL_CLK 2
#  define MOUSE_RIGHT_CLK 3
#  define MOUSE_SCRL_UP 4
#  define MOUSE_SCRL_DOWN 5
# else
#  define KEY_ESC 53

#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124

#  define KEYPAD_ZERO 82

#  define KEY_ONE 18
#  define KEY_TWO 19
#  define KEY_THREE 20
#  define KEY_FOUR 21
#  define KEY_FIVE 23
#  define KEY_SIX 22
#  define KEY_SEVEN 26
#  define KEY_EIGHT 28
#  define KEY_NINE 25
#  define KEY_ZERO 29

#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14
#  define KEY_R 15
#  define KEY_T 17
#  define KEY_Y 16

#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_H 4

#  define KEY_L 37

#  define MOUSE_LEFT_CLK 1
#  define MOUSE_SCRL_CLK 3
#  define MOUSE_RIGHT_CLK 2
#  define MOUSE_SCRL_UP 5
#  define MOUSE_SCRL_DOWN 4
# endif

# define WIN_SIZE 540
# define MAX_ITERATION 256

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define BUFFALO 4
# define HEARTMANDELBROT 5
# define CELTICMANDELBROT 6
# define TRICORN 7
# define BURNINGSHIPFIFTH 8
# define PERPENDICULARBURNINGSHIP 9
# define CELTICMANDELBAR 0

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx_macos/mlx.h"
# endif

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double		re;
	double		im;
}	t_complex;

typedef struct s_img
{
	int			endian;
	void		*img_ptr;
	int			size_line;
	char		*data_addr;
	int			bits_per_pixel;
}	t_img;

typedef struct s_fractal
{
	t_img		img;
	void		*mlx;
	void		*win;
	int			lock;
	u_int32_t	color;
	double		curr_x;
	double		curr_y;
	double		x_upper;
	double		x_lower;
	double		y_upper;
	double		y_lower;
	int			fractal;
	double		zoom_const;
}	t_fractal;

// color.c functions
void		change_color(int key, t_fractal *fractal);

// fractol.c functions
void		start_fractal(t_fractal *fractal, double x, double y);

// mandelbrot.c functions
int			is_mandelbrot_stable(t_complex c);
void		mandelbrot_set(t_fractal *fractal, int x, int y);

// julia.c functions
void		julia_set(t_fractal *fractal, int x, int y);
int			is_julia_stable(t_complex c, double x, double y);

// burning_ship.c functions
int			is_burning_ship_stable(t_complex c);
void		burning_ship_set(t_fractal *fractal, int x, int y);

// buffalo.c functions
int			is_bufallo_stable(t_complex c);
void		bufallo_set(t_fractal *fractal, int x, int y);

// heart_mandelbrot.c functions
int			is_heart_mandelbrot_stable(t_complex c);
void		heart_mandelbrot_set(t_fractal *fractal, int x, int y);

// celtic_mandelbrot.c functions
int			is_celtic_mandelbrot_stable(t_complex c);
void		celtic_mandelbrot_set(t_fractal *fractal, int x, int y);

// tricorn.c functions
int			is_tricorn_stable(t_complex c);
void		tricorn_set(t_fractal *fractal, int x, int y);

// burning_ship_fifth.c functions
int			is_burning_ship_fifth_stable(t_complex c);
void		burning_ship_fifth_set(t_fractal *fractal, int x, int y);

// perpendicular_burning_ship.c functions
int			is_perpendicular_burning_ship_stable(t_complex c);
void		perpendicular_burning_ship_set(t_fractal *fractal, int x, int y);

// celtic_mandelbar.c functions
int			is_celtic_mandelbar_stable(t_complex c);
void		celtic_mandelbar_set(t_fractal *fractal, int x, int y);

// utils.c functions
void		ft_strlower(char *src);
t_complex	init(double re, double im);
int			ft_strcmp(char *s1, char *s2);
void		going_in_style(char *message);

// helpers.c functions
void		change_variables(t_fractal *fractal);
double		convert_range(double old_value, double new_max, double new_min);
void		change_pixel_color(t_fractal *fractal, int x, int y, int color);
void		change_boundaries(t_fractal *fractal, int x, int y, double spec);

// parsing.c functions
void		init_mlx(t_fractal *fractal);
void		init_variables(t_fractal *fractal);
void		change_fractal(int key, t_fractal *fractal);
void		parsing(int argc, char **argv, t_fractal *fractal);
int			which_fractal(t_fractal *fractal, char *fractal_name);

// hooks.c functions
int			red_cross_hookers(void *param);
int			hookers(int key, t_fractal *fractal);
void		change_movement(int key, t_fractal *fractal);
int			mousemove_hookers(int x, int y, t_fractal *fractal);
int			mouse_hookers(int key, int x, int y, t_fractal *fractal);

#endif	/* FRACTOL_H */
