/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:30 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:08:20 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "command_table.h"

typedef struct dirent	t_dirent;

typedef struct s_wildcard
{
	char			*token;
	char			**path_parts;
	t_tok_list		*tokens_list;
}	t_wildcard;

// parsing.c
t_table		*parsing(t_tok_list *tokens_list);
int			single_cmd_parse(t_tok_node *from, t_tok_node *to);

// single_parsing.c
int			redefine_tokens(t_tok_node *from, t_tok_node *to);
int			single_cmd_parse(t_tok_node *from, t_tok_node *to);
int			check_tokens_pairs(t_tok_node *from, t_tok_node *to);
int			redefine_argument_token(t_tok_node *from, t_tok_node *to);
int			check_undefined_word_token(t_tok_node *from, t_tok_node *to);

// single_parsing_utils.c
void		token_counter(t_tok_node *temp, int *array);
void		redefine_tokens_loop(t_tok_node *temp, t_tok_node *to);

// pipe_parsing.c
int			pipe_parsing(t_table *cmd_table, t_tok_list *tokens_list);

// logic_parsing.c
int			logic_parsing(t_table *cmd_table, t_tok_list *tokens_list);

// default_parsing.c
int			default_parsing(t_table *cmd_table, t_tok_list *tokens_list);
t_string	fill_command(t_tok_node *from, t_tok_node *to);
t_string	*fill_params(t_tok_node *from, t_tok_node *to);
int			count_params(t_tok_node *from, t_tok_node *to);
int			fill_input(t_tok_node *from, t_tok_node *to);
int			fill_output(t_tok_node *from, t_tok_node *to);
int			fill_error(t_tok_node *from, t_tok_node *to);
int			fill_heredoc(t_tok_node *from, t_tok_node *to);
int			count_delimiters(t_tok_node *from, t_tok_node *to);
t_string	*fill_delimiter(t_tok_node *from, t_tok_node *to);
void		print_tok_list(t_tok_list *tokens_list);
void		print_cmd_table(t_table *cmd_table);
t_command	*new_cmd(t_tok_node *from, t_tok_node *to);
t_element	*new_cmd_element(t_command *cmd);
t_element	*new_element(int token);
void		add_element(t_table *cmd_table, t_element *element);
t_table		*init_cmd_table(void);

// wildcard_helpers.c
char		*shift_left(char *arg, int idx);
char		*join_free(char const *s1, char *s2);

// wildcard_utils.c
int			path_slash_count(char *s);
int			ft_strmatch(char *s1, char *s2, int i, int j);
char		*create_wildpath(char *s);
char		*append_slash(char *arg);
char		*clean_path(char *arg);

// wildcard.c
void		add_wild_argument(t_tok_list *tokens_list, char *arg);
void		wildcard_expansion(t_tok_list *tokens_list, char *tmp);
int			check_pattern(t_wildcard *w_env, int depth, int slash, \
														t_dirent *dir_format);
int			check_path_childs(t_wildcard *w_env, int slash, \
														t_dirent *dir_format);
void		process_wildcard(t_wildcard *w_env, char *start_path, int depth);

#endif
