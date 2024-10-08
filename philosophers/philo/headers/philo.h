/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:49:43 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/02 14:52:13 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define PHILO_MAX_COUNT 200

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"

typedef pthread_t		t_id;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_time;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
}	t_mutexes;

typedef struct s_times
{
	size_t	born_time;
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	int		philo_count;
	int		must_eat;
	int		has_eaten;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_mutexes	mutexes;
	t_id		thread_id;
	t_times		times;
}	t_philo;

typedef struct s_data
{
	t_mutex	*forks;
	t_philo	*philos;
	t_mutex	meal_lock;
	t_mutex	write_lock;
}	t_data;

#endif /* PHILO_H */
