/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:05:34 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/18 21:33:51 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*	ft_tolowercase(const char* str)
{
	int		i;
	char	lower[ft_strlen(str) + 1];
	
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		lower[i] = ft_tolower(str[i]);
		i++;
	}
	lower[i] = '\0';
	return (lower);
}
