/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:57:34 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:08:38 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

/* Defined Parameters  */
# define WIN_SIZE 500
# define MIN_ITERATIONS 256
# define MAX_ITERATIONS 300
# define VIEW_CHANGE_SIZE 60
# define DEFAULT_COLOR 265

# define SCALE 2
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5

/* Fractals */
enum e_Fractal
{
	None,
	Mandelbrot,
	Julia,
	Burning_Ship,
	Tricorn,
	Celtic_Mandelbar,
	Mandelbox,
	Heart_Mandelbrot
};

/* Fractal types  */
typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_image
{
	void	*p_img;
	void	*p_addr;
	int		pixel_bits;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	enum e_Fractal	type;
	unsigned int	color;
	double			zoom;
	double			mouse_x;
	double			mouse_y;
	double			offset_x;
	double			offset_y;
	int				iterations;	
	int				lock;
}	t_fractal;

typedef struct s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}	t_engine;

#endif /* FRACTAL_H  */
