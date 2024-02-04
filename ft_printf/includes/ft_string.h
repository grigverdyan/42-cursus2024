/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:04:59 by grverdya          #+#    #+#             */
/*   Updated: 2024/01/31 17:52:43 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

#endif
