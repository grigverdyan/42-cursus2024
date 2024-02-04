/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:14:30 by tsas              #+#    #+#             */
/*   Updated: 2022/07/06 21:37:35 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_color(int key, t_fractal *fractal)
{
	if (key == KEY_Q)
		fractal->color += 0x300000;
	else if (key == KEY_W)
		fractal->color += 0x030000;
	else if (key == KEY_E)
		fractal->color += 0x003000;
	else if (key == KEY_R)
		fractal->color += 0x000300;
	else if (key == KEY_T)
		fractal->color += 0x000030;
	else if (key == KEY_Y)
		fractal->color += 0x000003;
	else if (key == KEY_A)
		fractal->color -= 0x300000;
	else if (key == KEY_S)
		fractal->color -= 0x030000;
	else if (key == KEY_D)
		fractal->color -= 0x003000;
	else if (key == KEY_F)
		fractal->color -= 0x000300;
	else if (key == KEY_G)
		fractal->color -= 0x000030;
	else if (key == KEY_H)
		fractal->color -= 0x000003;
}
