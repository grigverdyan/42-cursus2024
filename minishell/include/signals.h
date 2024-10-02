/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:08:28 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:08:29 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

// signal_handler.c
void	signal_handler(void);
void	sigint_handler(int sig);
void	ignore_signal_handler(void);
void	default_signal_handler(void);
void	heredoc_signal_handler(void);

// signal_utils.c
void	hide_signal_output(void);

#endif
