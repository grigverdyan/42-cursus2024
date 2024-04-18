/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:08:42 by grverdya          #+#    #+#             */
/*   Updated: 2024/04/18 21:33:40 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*	ft_touppercase(const char* str)
{
	int		i;
	char	upper[ft_strlen(str) + 1];
	
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		upper[i] = ft_toupper(str[i]);
		i++;
	}
	upper[i] = '\0';
	return (upper);
}
