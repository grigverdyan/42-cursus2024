/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:31 by dapetros          #+#    #+#             */
/*   Updated: 2024/08/28 20:07:32 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCESSING_H
# define PREPROCESSING_H

// preprocessing.c
char	**preprocessing(char *inpt);

// preprocessing_utils.c
int		is_space(char chr);
int		is_valid_env(char ch);
int		is_quote(char ch, char *quote);
void	iterate_str(t_string str, t_string new_str, int *i, int *j);

// fill_env.c
char	*fill_env(t_string str);
int		required_word_len(char *string);
int		envir_len(char *string, int start, int *path_len);
void	fill_from_env(char *env_var, int *e_start, char *copy_to, int *start);

// clearing_quotes.c
char	*clear_quotes(char *string);

// clearing_quotes_utils.c
void	detect_env(char *string, int *i, int *j, char *new_str);
void	check_dollar(char *string, int *i, int *word_len, int *env_len);

//	check_quotes.c
int		check_quotes(char *inpt);
int		logic_or_pipe(char *inpt);
int		invalid_start_and_end(char *inpt);
int		invalid_logic_operator(char *inpt);

//smart_split.c
char	**smart_split(char *str);

// balanced_parentheses.c
int		is_balanced(char *exp);
void	free_par_list(t_node_par *list);
int		is_matching(char chr1, char chr2);
int		pop_parentheses(t_node_par **top_ref);
void	*push_parentheses(t_node_par **top_ref, int new_data);

#endif
