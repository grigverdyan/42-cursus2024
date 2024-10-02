/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:28:51 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:28:55 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	create_function_template(t_string f_name, int (*function)(char **))
{
	t_builtin	function_template;

	function_template.name = f_name;
	function_template.function = function;
	return (function_template);
}

void	init_builtins(void)
{
	g_data->builtins = malloc(sizeof(t_builtin) * BUILTINS_COUNT);
	g_data->builtins[_ECHO] = create_function_template("echo", echo);
	g_data->builtins[CD] = create_function_template("cd", cd);
	g_data->builtins[PWD] = create_function_template("pwd", pwd);
	g_data->builtins[EXPORT] = create_function_template("export", export);
	g_data->builtins[UNSET] = create_function_template("unset", unset);
	g_data->builtins[ENV] = create_function_template("env", env);
	g_data->builtins[EXIT] = create_function_template("exit", builtin_exit);
}
