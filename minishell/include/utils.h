/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:33 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:07:45 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

// ft_split.c
char			**ft_split(char const *s, char c);

// ft_str_split.c
char			**ft_str_split(char const *s, char *str);

// utils.c
void			free_array(char **arr);
void			close_fds(int **fds, int i_len);
char			command_exists(char *command);
int				change_cwd(char *new_pwd);
void			*error(char *msg, int code);
int				error_int(char *msg, int code);

// str_utils.c
int				contains(char *str, char ch);
int				text_len(t_string *text);
t_string		*get_full_param(t_string command_name, t_string *params);
int				ft_same_str(char *s1, char *s2);

// execution/execution_utils.c
char			find_execution_mode(t_command *command);
int				can_execute_next_command(void);
void			handle_delimiter(t_element	**current);
t_string		*get_envir(void);

// utils/heredoc.c
void			feel_input_file(t_command *command, int index);

// utils/ft_itoa.c
char			*ft_itoa(int n);
long long int	basic_atoi(const t_string str);

// utils/num_utils.c
int				num_len(int number);

// utils/redirection_handler.c
void			handle_redirections(t_command *command);
void			reset_redirections(t_command *command);
void			handle_heredocs(t_table *table);

// utils/printer.c
int				print_error_message(t_string subject, int error_code);

// utils/ft_strtrim.c
char			*ft_strtrim(const t_string str);
int				is_token(char ch);

#endif
