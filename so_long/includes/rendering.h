/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:55:51 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/17 16:56:16 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "so_long.h"

int		render_next_frame(t_engine *game);
void	get_imgs(t_engine *gmae, t_imgs *imgs);
void	render(t_engine *game);
void	put_img(int *arr, char symbol, t_engine *game, int *switcher);
void	print_moves(t_engine *game);

#endif  /* RENDERING_H */
