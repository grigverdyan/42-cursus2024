/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:04:16 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:06:35 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell_structs.h"

// builtins/builtins.c
int			env(char **args);
int			pwd(char **args);
int			echo(char **args);

// builtins/cd.c
int			cd(char **args);

// builtins/exit.c
int			builtin_exit(char **args);

// builtins/builtins_utils.c
int			is_builtin_with_name(t_string name);
int			(*get_function_with_name(t_string name))(char **argument);
int			is_valid_export_key(char *key);
void		not_valid_identifier(t_string command, t_string identifier);

// builtins/export_builtins.c
int			export(char **arguments);

// builtins/unset.c
int			unset(char **arguments);

#endif
