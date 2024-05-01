/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:46:35 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/17 16:46:48 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

int		move_player(int key, t_engine *game);
void	move(t_engine *game, int x_step, int y_step);
void	move_continue(t_engine *game, int x_step, int y_step);

#endif  /* GAME_h */
