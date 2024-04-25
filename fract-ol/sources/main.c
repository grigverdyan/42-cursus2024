/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:17:46 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/25 21:25:16 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx.h"
#include "visualization.h"
#include "initialization.h"
#include "utils.h"
#include "events.h"

int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc == 2)
	{
		start_engine(&engine, argv[1]);
		visualization(&engine);
		mlx_key_hook(engine.window, on_key_hook, &engine);
		mlx_mouse_hook(engine.window, on_mouse_hook, &engine);
		mlx_hook(engine.window, 6, 1L << 6, on_mouse_move, &engine);
		mlx_hook(engine.window, 17, 0, on_destroy, &engine);
		mlx_loop(engine.mlx);
	}
	else
	{
		help();
	}
	return (0);
}
