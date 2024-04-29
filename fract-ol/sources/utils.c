/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:24:14 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:25:42 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdlib.h>
#include <unistd.h>

void	print(const char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	throw_error(const char *message)
{
	print(message);
	exit(EXIT_FAILURE);
}

void	help(void)
{
	print(" +------------------ Fract-ol HELP ------------------------+\n");
	print(" |                                                         |\n");
	print(" | Usage: ./fractol [mandelbrot / julia / burning_ship     |\n");
	print(" |                   tricorn / celtic_mandelbar /          |\n");
	print(" |                   mandelbox ]                           |\n");
	print(" |                                                         |\n");
	print(" | e.g: ./fractol mandelbrot                               |\n");
	print(" |                                                         |\n");
	print(" |----------------------- KEYBOARD ------------------------|\n");
	print(" |                                                         |\n");
	print(" | Press ESC to close the window                           |\n");
	print(" | Press one of [1-6] to move to another fractal           |\n");
	print(" | Press [Q-Y][A-H] keys to change the color of the fractal|\n");
	print(" | Use mouse scroll to zoom in and out of the fractal      |\n");
	print(" | Press the arrow keys to change the viewpoint            |\n");
	print(" | Press L to lock Julia's fractal                         |\n");
	print(" +---------------------------------------------------------+\n");
	exit(EXIT_SUCCESS);
}
