#include <pthread.h>
#include <stdlib.h>
#include "philo.h"
#include "simulation.h"
#include "utils.h"

void    check_params(int argc, char **argv)
{
    long    num;
    int     i;

    if (argc != 5 || argc != 6)
        help();
    i = 0;
    while (++i < argc)
    {
        num = ft_atoi(argv[i]);
        if (i == 1 && (num < 1 || num > PHILO_MAX_COUNT))
            error_message("[Error] Wrong Philo Count\n", EXIT_FAILURE);
        if (i == 5 && (num < 0 || num > INT_MAX))
            error_message("[Error] Wrong Philo Eating Count\n", EXIT_FAILURE);
        if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
            error_message("[Error] Wrong Parameters\n", EXIT_FAILURE);
    }
}

void    init_data(t_data *dt, char **argv)
{
    t_philo philos[PHILO_MAX_COUNT];
    t_mutex forks[PHILO_MAX_COUNT];
    int     i;
    int     philo_count;

    if (pthread_mutex_init(&dt->write_lock, NULL) != 0
            || pthread_mutex_init(&dt->meal_lock, NULL) != 0)
        destroy_mutexes(dt, "[Error] Mutex Fault\n", -1, EXIT_FAILURE);
    dt->forks = forks;
    i = -1;
    philo_count = ft_atoi(argv[1]);
    while (++i < philo_count)
    {
        if (pthread_mutex_init(&dt->forks[i], NULL) != 0)
            destroy_mutexes(dt, "[Error] Mutex Fault\n", i, EXIT_FAILURE);
    }
    dt->philos = philos;
    init_philos(dt, argv);
}

void    init_philos(t_data *dt, char **argv)
{
    int i;
    int     philo_count;

    philo_count = ft_atoi(argv[1]);
    i = -1;
    while (++i < philo_count)
    {
        dt->philos[i].id = i;
        dt->philos[i].times.born_time = get_time_now();
        dt->philos[i].times.last_meal = get_time_now();
        dt->philos[i].times.die = ft_atoi(argv[2]);
        dt->philos[i].times.eat = ft_atoi(argv[3]);
        dt->philos[i].times.sleep = ft_atoi(argv[4]);
        dt->philos[i].times.must_eat = (argv[5]) ? ft_atoi(argv[5]) : -1;
        dt->philos[i].times.has_eaten = 0;
        dt->philos[i].times.philo_count = philo_count;
        dt->philos[i].mutexes.left_fork = &dt->forks[i];
        dt->philos[i].mutexes.right_fork = (i == 0) ? &dt->forks[philo_count - 1] : &dt->forks[i - 1];
        dt->philos[i].mutexes.write_lock = &dt->write_lock;
        dt->philos[i].mutexes.meal_lock = &dt->meal_lock;
    }
}

void    simulation(t_data *dt, int ph_count)
{
    int i;

    i = -1;
    while (++i < ph_count)
    {
        if (pthread_create(&dt->philos[i].thread_id, NULL, routine, &dt->philos[i]) != 0)
            destroy_mutexes(dt, "[Error] Thread creation fault\n", ph_count, EXIT_FAILURE);
    }
}