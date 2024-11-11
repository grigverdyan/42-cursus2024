/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:59:21 by grverdya          #+#    #+#             */
/*   Updated: 2023/10/29 23:02:24 by vkrivogo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define NUM_COUNT 41 
# define NUM_LEN 39

typedef struct s_line
{
	char	*key;
	char	*value;
}	t_line;

int		ft_exit(char *str, int ret_type);
int		is_space(char c);
char	*ft_isspace(char *str);
char	*ft_atoi_string(char *str, int for_dict);
char	**get_default_nums(void);
void	set_values(char **mat);
void	set_values1(char **mat);

#endif 
