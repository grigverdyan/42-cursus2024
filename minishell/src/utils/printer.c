/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:16:27 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:16:28 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error_message(t_string subject, int error_code)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(subject, 2);
	ft_putstr_fd(": ", 2);
	if (error_code == NO_SUCH_FILE_OR_DIR)
		ft_putstr_fd("No such file or directory\n", 2);
	else if (error_code == COMMAND_NOT_FOUND)
		ft_putstr_fd("Command not found\n", 2);
	else if (error_code == TOO_MANY_ARGUMENTS)
		ft_putstr_fd("Too many arguments\n", 2);
	else if (error_code == NUMERIC_ARGUMENT_REQUIRED)
		ft_putstr_fd("Numeric argument required\n", 2);
	else if (error_code == HOME_NOT_SET)
		ft_putstr_fd("HOME not set\n", 2);
	else if (error_code == NOT_VALID_IDENTIFIER)
		ft_putstr_fd("Not a valid identifier\n", 2);
	else if (error_code == RSRC_TEMP_UNAVAILABLE)
		ft_putstr_fd("Resource temporarily unavailable\n", 2);
	return (1);
}
