#include "utils.h"

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    while (str[len])
        ++len;
    return (len);
}

long    ft_atoi(const char *str)
{
	int     i;
	int     sign;
	long	number;

	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		++i;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i] == '-')
			sign *= -1;
	number = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
        if (number > INT_MAX)
            break;
		number *= 10;
		number += (str[i] - '0');
		++i;
	}
	return (sign * number);
}