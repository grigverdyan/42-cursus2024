/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:09:07 by stadevos          #+#    #+#             */
/*   Updated: 2022/07/07 22:07:33 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] != '\0' && s2[idx] != '\0')
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_strlower(char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (src[i] >= 'A' && src[i] <= 'Z')
			src[i] += 32;
		else
		{
			i++;
			continue ;
		}
		i++;
	}
}

void	going_in_style(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	exit(1);
}

t_complex	init(double re, double im)
{
	t_complex	new;

	new.re = re;
	new.im = im;
	return (new);
}
