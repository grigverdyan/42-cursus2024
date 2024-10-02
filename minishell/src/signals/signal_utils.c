/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:38:40 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 19:38:41 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hide_signal_output(void)
{
	struct termios	termios_params;

	if (tcgetattr(0, &termios_params))
		perror("minishell: tcgetattr");
	termios_params.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &termios_params))
		perror("minishell: tcsetattr");
}

void	heredoc_signal(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	hide_signal_output();
	rl_replace_line("\0", 0);
	g_data->ctrl_c_pressed = 1;
}

void	heredoc_signal_handler(void)
{
	signal(SIGINT, heredoc_signal);
	signal(SIGQUIT, SIG_IGN);
}
