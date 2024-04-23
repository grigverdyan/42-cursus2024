/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:51:48 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/23 21:51:49 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

#include "fractal.h"

int	on_destroy(t_engine *engine);
int	on_mouse_hook(int key, int x, int y, t_engine *engine);
int	on_key_hook(int key, t_engine* engine);
int	on_mouse_move(int x, int y, t_engine *engine);

#endif /* EVENTS_H */
