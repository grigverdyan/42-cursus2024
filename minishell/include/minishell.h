/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:24 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:07:25 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <termios.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>

# include "linkedlist.h"
# include "minishell_structs.h"
# include "tokenizing.h"
# include "parsing.h"
# include "preprocessing.h"
# include "builtins.h"
# include "minishell_macros.h"
# include "utils.h"
# include "signals.h"
# include "command_table.h"
# include "get_next_line.h"
# include "libft.h"

// global variable
extern t_data		*g_data;

// src/data.c
void		guard_free(void *data);
void		free_and_exit(int status);
void		free_data(void);
void		set_data_path(t_list *list);
char		*get_command_path(char *command);

// src/pipex.c
int			command_child(int index);
int			execute_with_pipe(t_table *table);

// src/init.c
void		init_builtins(void);
t_list		*init_env_list(char **envir);
t_string	*init_envir(char **envir);
t_data		*data_init(char **envv);

// src/reset.c
void		reset_data(void);
void		reset_after_execution(void);

#endif
