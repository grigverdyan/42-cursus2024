/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:59:00 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/02 15:05:21 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void	error_message(const char *str)
{
	if (str)
		write(2, str, ft_strlen(str) + 1);
}

void	help(void)
{
	printf("\
	./philo number_of_philosophers \
    time_to_die time_to_eat time_to_sleap \
    [number_of_times_each_philosopher_must_eat]\n\n\
    number_of_philosophers: Number of philosophers and forks(1 to 200)\n\
    time_to_die(ms): Time of die if not eating since lastmeal\n\
    time_to_eat(ms): Time of eating\n\
    time_to_sleep(ms): Time of sleeping\n\
    [number_of_times_each_philosopher_must_eat]: Eating count\n");
}

void	destroy_mutexes(t_data *dt, const char *str, int mutexes, int signal)
{
	while (--mutexes >= 0)
		pthread_mutex_destroy(&dt->forks[mutexes]);
	pthread_mutex_destroy(&dt->write_lock);
	pthread_mutex_destroy(&dt->meal_lock);
	free(dt->forks);
	free(dt->philos);
	error_message(str);
}

void	print_info(t_philo *philo, char *info)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = get_time_now() - philo->times.born_time;
	printf(GREEN"%ld"RESET" %d%s\n", time, philo->id + 1, info);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}
