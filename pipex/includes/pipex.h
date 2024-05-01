/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverdyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:44:09 by gverdyan          #+#    #+#             */
/*   Updated: 2022/08/12 15:30:59 by gverdyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"

int		**open_pipes(int argc);
void	pipex(int **pipes, t_args args);
void	my_exec(char **cmd, char **envp);
char	**envp_parsing(char **envp);
void	close_pipes(int **pipes, int i);

#endif	/* PIPEX_H */
