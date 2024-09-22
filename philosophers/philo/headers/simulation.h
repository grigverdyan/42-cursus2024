#ifndef SIMULATION_H
# define SIMULATION_H

void    check_params(int argc, char **argv);
void    init_data(t_data *en, char **argv);
void    init_philos(t_data *dt, char **argv);
void    simulation(t_data *dt, int ph_count);

#endif /* SIMULATION_H */