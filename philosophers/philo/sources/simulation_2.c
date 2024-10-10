/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:51:17 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/02 15:51:19 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "philo.h"
#include "simulation.h"
#include "utils.h"

int	check_params(int argc, char **argv)
{
	long	num;
	int		i;

	if (argc != 5 && argc != 6)
		help();
	i = 0;
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
		{
			error_message("[Error] Wrong Philo Count\n", EXIT_FAILURE);
			return (0);
		}
		if (i == 5 && (num < 0 || num > INT_MAX))
		{
			error_message("[Error] Wrong Philo Eating Count\n", EXIT_FAILURE);
			return (0);
		}
		if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
		{
			error_message("[Error] Wrong Parameters\n", EXIT_FAILURE);
			return (0);
		}
	}
}

void	init_data(t_data *dt, char **argv)
{
	int		i;
	int		philo_count;

	if (pthread_mutex_init(&dt->write_lock, NULL) != 0
		|| pthread_mutex_init(&dt->meal_lock, NULL) != 0)
		destroy_mutexes(dt, "[Error] Mutex Fault\n", -1, EXIT_FAILURE);
	i = -1;
	philo_count = ft_atoi(argv[1]);
	dt->forks = (t_mutex *)malloc(sizeof(t_mutex) * philo_count);
	while (++i < philo_count)
	{
		if (pthread_mutex_init(&dt->forks[i], NULL) != 0)
			destroy_mutexes(dt, "[Error] Mutex Fault\n", i, EXIT_FAILURE);
	}
	dt->philos = (t_philo *)malloc(sizeof(t_philo) * philo_count);
	init_philos(dt, argv);
}

void	init_philos(t_data *dt, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		dt->philos[i].id = i;
		dt->philos[i].times.born_time = get_time_now();
		dt->philos[i].times.last_meal = get_time_now();
		dt->philos[i].times.die = ft_atoi(argv[2]);
		dt->philos[i].times.eat = ft_atoi(argv[3]);
		dt->philos[i].times.sleep = ft_atoi(argv[4]);
		dt->philos[i].times.must_eat = -1;
		if (argv[5])
			dt->philos[i].times.must_eat = ft_atoi(argv[5]);
		dt->philos[i].times.has_eaten = 0;
		dt->philos[i].times.philo_count = ft_atoi(argv[1]);
		dt->philos[i].mutexes.left_fork = &dt->forks[i];
		if (i == 0)
			dt->philos[i].mutexes.right_fork = &dt->forks[ft_atoi(argv[1]) - 1];
		else
			dt->philos[i].mutexes.right_fork = &dt->forks[i - 1];
		dt->philos[i].mutexes.write_lock = &dt->write_lock;
		dt->philos[i].mutexes.meal_lock = &dt->meal_lock;
	}
}
