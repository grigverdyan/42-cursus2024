/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:28:53 by stadevos          #+#    #+#             */
/*   Updated: 2022/03/20 13:17:56 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t	idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)dest;
	while (idx < n)
	{
		ptr[idx] = '\0';
		idx++;
	}
}
