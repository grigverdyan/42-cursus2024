/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:55:03 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/02 14:56:01 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "simulation.h"

#include "utils.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_params(argc, argv) == 0)
		return (1);
	init_data(&data, argv);
	simulation(&data, data.philos[0].times.philo_count);
	destroy_mutexes(&data, NULL, data.philos->times.philo_count, EXIT_SUCCESS);
	return (0);
}
