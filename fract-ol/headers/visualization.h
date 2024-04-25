/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:17:08 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:10:08 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H

# include "fractal.h"

void	visualization(t_engine *engine);
void	set_pixel_color(t_engine *engine, int x, int y, int color);
int		calc_fractal(t_fractal *fract, t_complex *c, int x, int y);

#endif /* VISUALIZATION_H */
