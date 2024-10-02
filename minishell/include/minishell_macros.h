/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_macros.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:26 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:07:28 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MACROS_H
# define MINISHELL_MACROS_H

// BOOLEAN
# define TRUE	1
# define FALSE	0

// DELIMITERS

# define _PIPE	1
# define OPEN_PAR	4
# define CLOS_PAR	5

// builtins
# define BUILTINS_COUNT	7

# define _ECHO		0
# define CD			1
# define PWD		2
# define EXPORT		3
# define UNSET		4
# define ENV		5
# define EXIT		6

// execution_mode
# define WITH_PIPE	0

// command_element_types
# define _DELIMITER	0
# define COMMAND	1

// command_execution_modes
# define BUILTIN	1
# define EXECVE		2

// pipe/logic or single mode
# define _LOGIC		2
# define SINGLE		3

// error_messages

# define COMMAND_NOT_FOUND			1
# define NO_SUCH_FILE_OR_DIR		2
# define TOO_MANY_ARGUMENTS			3
# define NUMERIC_ARGUMENT_REQUIRED	4
# define HOME_NOT_SET				5
# define NOT_VALID_IDENTIFIER		6
# define RSRC_TEMP_UNAVAILABLE		7
#endif
