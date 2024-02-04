/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:05:03 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 14:32:27 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	lnb;
	char			a;

	lnb = n;
	if (n < 0)
	{
		lnb = (unsigned int)n;
		write(fd, &"-", 1);
		lnb = -1 * lnb;
	}
	if (lnb > 9)
	{
		ft_putnbr_fd(lnb / 10, fd);
		a = lnb % 10 + 48;
		write(fd, &a, 1);
	}
	else
	{
		a = lnb + 48;
		write(fd, &a, 1);
	}
}
