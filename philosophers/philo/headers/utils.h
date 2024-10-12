/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:53:30 by grverdya          #+#    #+#             */
/*   Updated: 2024/10/11 16:32:14 by grverdya         ###   ########.fr       */
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
int		error_message(const char *str);
int		destroy_mutexes(t_data *dt, const char *str, int mutexes);
void	print_info(t_philo *philo, char *info);
int		help(void);

#endif /* UTILS_H */
