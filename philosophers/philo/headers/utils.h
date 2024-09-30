#ifndef UTILS_H
#define UTILS_H

#include <limits.h>
#include "philo.h" 

// Libft functions
size_t  ft_strlen(const char *str);
long    ft_atoi(const char *str);

void	error_message(const char *str, int signal);
void	destroy_mutexes(t_data *dt, const char *str, int mutexes, int signal);
size_t	get_time_now(void);
void	ft_usleep(size_t mls);
void	print_info(t_philo *philo, char *info);
void    help(void);

#endif /* UTILS_H */