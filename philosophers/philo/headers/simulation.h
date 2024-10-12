/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:52:46 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/11 16:33:22 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <stdbool.h>

int		check_params(int argc, char **argv);
int		init_data(t_data *en, char **argv);
void	init_philos(t_data *dt, char **argv);
int		simulation(t_data *dt, int ph_count);
void	basic_routine(t_philo *philo);
void	*routine(void *arg);
void	*control(void *arg);
bool	eat_control(t_philo *philos);

#endif /* SIMULATION_H */
