/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:05:39 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/11 16:32:45 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo.h"
#include "simulation.h"
#include "utils.h"

void	basic_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_info(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_info(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	print_info(philo, " is eating");
	philo->times.last_meal = get_time_now();
	philo->times.has_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_info(philo, " is sleeping");
	ft_usleep(philo->times.sleep);
	print_info(philo, " is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.born_time = get_time_now();
	philo->times.last_meal = get_time_now();
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	while (true)
		basic_routine(philo);
	return (NULL);
}

bool	eat_control(t_philo *philos)
{
	int	i;
	int	eaten_full;

	if (philos[0].times.must_eat == -1)
		return (false);
	eaten_full = 0;
	i = -1;
	while (++i < philos[0].times.philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].times.has_eaten >= philos[i].times.must_eat)
			++eaten_full;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (philos[0].times.philo_count == eaten_full)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (true);
	}
	return (false);
}

void	*control(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (true)
	{
		i = -1;
		while (++i < philos[0].times.philo_count)
		{
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (get_time_now()
				- philos[i].times.last_meal > philos[i].times.die)
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_info(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
		}
		if (eat_control(philos) == true)
			return (NULL);
	}
}

int	simulation(t_data *dt, int ph_count)
{
	int		i;
	t_id	control_id;

	if (pthread_create(&control_id, NULL, &control, dt->philos) != 0)
		return (destroy_mutexes(dt, "[Thread Creation ERROR]\n", ph_count));
	i = -1;
	while (++i < ph_count)
	{
		if (pthread_create(&dt->philos[i].thread_id, NULL,
				routine, &dt->philos[i]) != 0)
			return (destroy_mutexes(dt, "[Error] Thread creation fault\n",
					ph_count));
	}
	if (pthread_join(control_id, NULL) != 0)
		return (destroy_mutexes(dt, "[Thread Join ERROR]\n", ph_count));
	i = -1;
	while (++i < ph_count)
	{
		if (pthread_detach(dt->philos[i].thread_id) != 0)
			return (destroy_mutexes(dt, "[Thread Detach ERROR]\n", ph_count));
	}
	return (1);
}
