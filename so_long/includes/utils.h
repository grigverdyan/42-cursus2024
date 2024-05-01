/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:04:42 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/17 18:39:37 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <stdio.h>
# include "so_long.h"

void	init_game(int argc, char **argv, t_engine *game);
void	display_info(void);
void	error_message(char *sms);
void	args_valid(int argc, char **argv);
void	get_player_coords(t_engine *game);
void	close_window_free_and_exit(t_engine *game, char *sms);
int		on_destroy_exit(t_engine *game);

#endif	/* UTILS_H */
