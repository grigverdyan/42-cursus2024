/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 06:49:03 by stadevos          #+#    #+#             */
/*   Updated: 2022/04/02 10:15:55 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reverse(char *ptr)
{
	int	start;
	int	end;
	int	temp;
	int	idx;

	start = 0;
	end = ft_strlen(ptr) - 1;
	temp = 0;
	idx = 0;
	while (idx <= end)
	{
		temp = ptr[start];
		ptr[start] = ptr[end];
		ptr[end] = temp;
		idx++;
		start++;
		end--;
	}
	return (ptr);
}

static int	number_length(int n)
{
	int	copy;
	int	len;

	copy = n;
	len = 0;
	while (copy)
	{
		len++;
		copy = copy / 10;
	}
	if (n < 0)
		len++;
	else if (n == 0)
		len = 1;
	return (len);
}

char	*ft_itoa(int n)
{
	int				length;
	int				idx;
	char			*ptr;
	unsigned int	number;

	length = number_length(n);
	number = n;
	if (n < 0)
		number = -1 * (unsigned int)n;
	ptr = (char *)malloc((length + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	idx = 0;
	if (number == 0)
		ptr[idx++] = '0';
	while (number)
	{
		ptr[idx++] = (number % 10) + 48;
		number = number / 10;
	}
	if (n < 0)
		ptr[idx++] = '-';
	ptr[idx] = '\0';
	reverse(ptr);
	return (ptr);
}
