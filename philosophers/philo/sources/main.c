#include <stdlib.h>
#include "philo.h"
#include "simulation.h"

#include "utils.h"


int main(int argc, char **argv)
{
    t_data    data;

    check_params(argc, argv);
    init_data(&data, argv);
    simulation(&data, data.philos[0].times.philo_count);
    destroy_mutexes(&data, NULL, data.philos->times.philo_count, EXIT_SUCCESS);
    return (EXIT_SUCCESS);
}