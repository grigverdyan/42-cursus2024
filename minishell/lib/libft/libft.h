/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grverdya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:23:14 by grverdya          #+#    #+#             */
/*   Updated: 2024/08/28 20:29:28 by grverdya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list_libft
{
	void				*content;
	struct s_list_libft	*next;
}	t_list_libft;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isascii(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_lstsize(t_list_libft *lst);
int				ft_isspace(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_lstadd_back(t_list_libft **lst, t_list_libft *new);
void			ft_lstdelone(t_list_libft *lst, void (*del)(void*));
void			ft_lstclear(t_list_libft **lst, void (*del)(void*));
void			ft_lstiter(t_list_libft *lst, void (*f)(void *));
void			ft_lstadd_front(t_list_libft **lst, t_list_libft *new);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *s1, const char *s2, size_t l);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim_libft(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t len);
t_list_libft	*ft_lstnew(void *content);
t_list_libft	*ft_lstlast(t_list_libft *lst);
t_list_libft	*ft_lstmap(t_list_libft *l, void *(*f)(void *),
					void (*d)(void *));

#endif /* LIBFT_H */
