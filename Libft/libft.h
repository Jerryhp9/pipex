/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:28:24 by jhor              #+#    #+#             */
/*   Updated: 2025/07/18 14:43:11 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_nodes
{
	struct s_nodes	*prev_link;
	int				data;
	struct s_nodes	*next_link;
}	t_nodes;

int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t n, size_t s);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strjoinv(int nbr, ...);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *substr, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_lstiter(t_nodes *lst, void (*f)(void *));
int				ft_print_char(char c);
size_t			ft_strlen(const char *str);
long			ft_print_digit(long long num, char *base);
int				ft_print_str(char *s);
int				ft_print_lower_hexa(unsigned int nbr);
int				ft_print_upper_hexa(unsigned int nbr);
unsigned long	ft_print_pointer(void *num);
unsigned long	ft_print_digit1(unsigned long n, char *base);
int				format_specifiers(char format, va_list *list);
int				ft_printf(const char *format, ...);

#endif