/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:28 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:07:29 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef char *				t_string;
typedef int					t_delimiter;
typedef char				t_type;
typedef struct s_command	t_command;
typedef struct s_table		t_table;
typedef struct s_element	t_element;

struct s_command
{
	t_string	command;
	t_string	*params;
	int			in;
	int			out;
	int			error;
	int			with_hd;
	t_string	*hd_word;
};

struct s_element
{
	t_command	*command;
	t_delimiter	delimiter;
	t_type		type;

	t_element	*next;
	t_element	*previous;
};

struct s_table
{
	t_element	*head;
	t_element	*tail;
	int			count;
	int			execution_mode;
	int			status;
};

typedef int					(*t_func)(char **);

typedef struct s_builtin
{
	t_string	name;
	t_func		function;
}	t_builtin;

typedef struct s_data
{
	t_builtin	*builtins;
	t_table		*command_table;
	t_list		*env_list;
	char		**envir;
	char		**path;
	int			**fds;

	t_string	pwd;
	t_string	temp_dir;
	int			last_status;
	int			open_par_count;
	int			connection_type;
	int			pipe_logic_mode;
	int			wildcard_result;
	int			wildcard_ends_slash;
	int			ctrl_c_pressed;
}				t_data;

#endif
