/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:55:48 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 22:52:06 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_string.h"

# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
char	*file_read(int fd, char *str);
char	*ret_line(char *str);
char	*updated_str(char *str);

#endif
