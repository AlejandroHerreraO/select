/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:14:24 by aherrera          #+#    #+#             */
/*   Updated: 2018/05/27 19:44:42 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef unsigned long long	t_ull;

void						*ft_memset(void *b, int c, size_t n);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dst, void *src, size_t n);
void						*ft_memccpy(void *dst, void *src, int c, size_t n);
void						*ft_memmove(void *dst, const void *src, size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
size_t						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strncpy(char *dst, const char *src, size_t n);
char						*ft_strcat(char *dst, const char *src);
char						*ft_strncat(char *dst, const char *src, size_t n);
size_t						ft_strlcat(char *dst, const char *src, size_t nt);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *s1, const char *s2);
char						*ft_strnstr(const char *s1, const char *s2,
							size_t n);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1, const char *s2,
							size_t n);
int							ft_atoi(const char *c);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isdigitstr(char *st);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						ft_strclr(char *as);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
char						*ft_strrev(char *s);
void						ft_strdel(char **as);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, void (*f)(unsigned int,
							char *));
char						*ft_strmap(char *s, char (*f)(char));
char						*ft_strmapi(char *s, char (*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1, char const *s2,
							size_t n);
char						*ft_strsub(char const *s1, unsigned int start,
							size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s);
int							ft_putchar(int c);
void						ft_putwchar(wint_t c);
void						ft_putstr(char const *s);
void						ft_putwstr(wchar_t *s, int i);
void						ft_putendl(char const *s);
int							ft_iswhitespace(char c);
int							ft_iswhitespacestr(char *s);
void						ft_putnbr(int n);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char const *s, int fd);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr_fd(int n, int fd);
char						*ft_itoa(int n);
char						**ft_strsplit(char *str, char c);
int							get_next_line(const int fd, char **line);
int							get_next_line2(const int fd, char **line);
char						*ft_ctos(char c);
void						ft_strshift(char **st, char c);
int							ft_diff(int a, int b);
int							ft_small(int a, int b);
char						*ft_utoa(t_ull n, t_ull b, char x, int l);
void						ft_strcomb(char **st, char *s, int order, int n);

#endif
