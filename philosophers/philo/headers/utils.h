/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:53:30 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/02 15:03:50 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>
# include "philo.h" 

// Libft functions
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);

size_t	get_time_now(void);
void	ft_usleep(size_t mls);
void	error_message(const char *str, int signal);
void	destroy_mutexes(t_data *dt, const char *str, int mutexes, int signal);
void	print_info(t_philo *philo, char *info);
void	help(void);

#endif /* UTILS_H */
