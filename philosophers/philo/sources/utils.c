#include <stdio.h>

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	sign = 1;
	i = 0;
	while (str[i] && is_space(str[i]))
		++i;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	number = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		number *= 10;
		number += (str[i] - '0');
		++i;
	}
	return (sign * number);
}

void    help(void)
{
    printf("./philo number_of_philosophers \
            time_to die time_to_eat time_to_sleap \
            [number_of_times_each_philosopher_must_eat]\n\n \
            number_of_philosophers: Number of philosophers and forks\n\
            time_to_die(ms): Time of die if not eating since lastmeal\n\
            time_to_eat(ms): Time of eating\n\
            time_to_sleep(ms): Time of sleeping\n\
            number_of_times_each_philosopher_must_eat: Eating count\n");            
}