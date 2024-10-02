/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:17 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:07:19 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_TABLE_H
# define COMMAND_TABLE_H

# include "minishell_structs.h"

int	execute_command_table(t_table *command_table);
int	execute_command(t_command *command, char mode);

#endif
