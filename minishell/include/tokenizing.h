/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:08:34 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:08:35 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

# define RED_INPUT		1	// <
# define RED_OUTPUT		2	// >
# define RED_OUT_APP	3	// >>
# define HERE_DOC		4	// <<
# define PIPE			5	// |
# define AND_OR			6	// &&
# define OR_IF			7	// ||
# define EXIT_STATUS	8	// &?
# define OPTION			9	// --\s -\s
# define WORD			10	// \s
# define FD				11	// \d
# define DELIMITER		12	// <<\s
# define L_BRACE		13	// (
# define R_BRACE		14	// )
# define FILE			15	// \s
# define CMD			16	// \s
# define ARGUMENT		17	// \s
# define NO_TOKEN		18	// n\a

typedef struct s_node_par	t_node_par;

struct s_node_par
{
	char			data;
	t_node_par		*next;
};

typedef struct s_tok_node	t_tok_node;

struct s_tok_node
{
	int				key;
	char			*value;
	t_tok_node		*next;
	t_tok_node		*prev;
};

typedef struct s_tok_list
{
	t_tok_node		*head;
	t_tok_node		*tail;
	int				count;
}	t_tok_list;

// tokenizing.c
t_tok_list	*tokenizer(char **line);
int			consist(char chr, char *spec_chars);
int			contain_chars(char *str, char *substr);
void		match_token(char *token, t_tok_list *tokens_list);

// token_utils.c
t_tok_list	*new_tok_list(void);
t_tok_node	*new_tok_node(int key, char *value);
void		add_tok(t_tok_list *list, t_tok_node *node);
void		free_tok_list(t_tok_list *list);

// token_helpers.c
int			str_len(char *str);
int			str_cmp(char *str1, char *str2);
int			starts_with(char *token, char start);
int			starts_with_mul(char *token, char *start);
int			starts_with_string(char *str1, char *str2);

// main_token_matching.c
void		pipe_token(char *token, t_tok_list *tokens_list);
void		here_doc_token(char *token, t_tok_list *tokens_list);
void		redirection_input_token(char *token, t_tok_list *tokens_list);
void		redirection_output_token(char *token, t_tok_list *tokens_list);
void		redirection_output_app_token(char *token, t_tok_list *tokens_list);

// bonus_token_matching.c
int			check_for_word(char *token);
int			check_for_option(char *token);
int			ends_with_char(char *str, char chr);
int			starts_with_char(char *str, char chr);
void		or_if_token(char *token, t_tok_list *tokens_list);
void		and_if_token(char *token, t_tok_list *tokens_list);
void		check_both_parentheses(t_tok_list *tokens_list, int token, \
																char *temp);
void		parentheses_middleware(t_tok_list *tokens_list, int token, \
														char *temp, char dir);

#endif
