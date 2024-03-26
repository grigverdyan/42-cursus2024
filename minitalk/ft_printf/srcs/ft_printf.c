/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:05:42 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/31 19:25:17 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	char_cnt;
	void	*ptr;

	ptr = NULL;
	i = -1;
	char_cnt = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", str[i]))
				char_cnt += ft_specifier(str[i], ap);
		}
		else
			char_cnt += ft_putchar(str[i]);
	}
	va_end(ap);
	return (char_cnt);
}

size_t	ft_specifier(const char c, va_list ap)
{
	size_t	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += config_specifier(va_arg(ap, int), "0123456789", c);
	else if (c == 'u')
		count += config_specifier(va_arg(ap, unsigned), "0123456789", c);
	else if (c == 'x')
		count += config_specifier(va_arg(ap, unsigned), "0123456789abcdef", c);
	else if (c == 'X')
		count += config_specifier(va_arg(ap, unsigned), "0123456789ABCDEF", c);
	else if (c == 'p')
		count += config_specifier(va_arg(ap, long), "0123456789abcdef", c);
	return (count);
}
