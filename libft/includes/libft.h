/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 10:55:41 by agama             #+#    #+#             */
/*   Updated: 2018/08/31 08:31:30 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef int			t_bool;

typedef struct		s_rgb
{
	float			r;
	float			g;
	float			b;
}					t_rgb;

typedef struct		s_hsb
{
	float			h;
	float			s;
	float			b;
}					t_hsb;

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vector;

void				*ft_memset(void *str, int c, size_t num_bts);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void	*dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t dest_size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ***************** Additional Functions *************************************
*/

void				ft_atoi_add_digit_u(const char c, unsigned int *number);
void				ft_putnbr_large_fd(intmax_t number, int file_descriptor);
int					ft_count_digits_ularge(uintmax_t number);
intmax_t			ft_abs_large(intmax_t number);
void				ft_itoa_write(char *last_digit, uintmax_t number);
void				ft_putstrn_fd(char const *source, size_t max_length
								, int file_descriptor);
size_t				ft_wstrlen(const wchar_t *source);
void				ft_putcharn(char c, size_t number);
void				ft_putcharn_fd(char c, size_t number, int file_descriptor);
void				ft_putstr_lateral_fd(char const *source
										, int file_descriptor);
size_t				ft_count_chars(const char *haystack, char needle
								, size_t length);
char				*ft_itoa_large(intmax_t number);
char				*ft_itoa_ularge(uintmax_t number);
char				*ft_base_itoa(uintmax_t number, int base);
void				ft_putstr_lateral_fd(const char *source
										, int file_descriptor);
void				ft_strtolower(char *str);
int					ft_abs(int n);
void				ft_bubblesort_array(char **tab, size_t n);
int					ft_clamp(int n, int min, int max);
int					ft_error(char *s);
float				ft_fclamp(float n, float min, float max);
int					ft_htoi(char *s);
int					*ft_intnew(size_t size);
int					ft_is_power_of_x(unsigned n, unsigned x);
int					ft_isblank(char c);
int					ft_isspace(char c);
int					ft_iswascii(int wc);
char				*ft_itoa_base(int value, int b);
char				*ft_ldtoa(double n, int precision);
char				*ft_lltoa_base(long long n);
t_list				*ft_lstswap(t_list *lst1, t_list *lst2);
void				ft_memswap(void *a, void *b);
double				ft_pow(double n, int pow);
void				ft_puthex(int n);
void				ft_putnbr_base(int n, int b);
void				ft_putstr_free(char const *s);
int					ft_putwchar(unsigned wc, int wlen);
int					ft_putwstr(wchar_t *s);
int					ft_rand(int min, int max);
int					*ft_range(int min, int max);
long				ft_round(double n, int precision);
char				*ft_strctrim(char const *s, char c);
char				*ft_strdupfree(const char *s1);
char				*ft_strjoinfree(char *s1, char *s2, char control);
unsigned int		ft_strlcpy(char *dst, char *src, unsigned int size);
int					ft_strlencmp(const char *s1, const char *s2);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strnjoin(const char *s1, const char *s2, size_t len);
char				*ft_strnjoinfree(const char *s1, const char *s2, size_t len
									, char c);
char				*ft_strrev(char *s);
void				ft_swap(int *a, int *b);
char				*ft_ulltoa_base(unsigned long long n, int b, int lowup);
size_t				ft_wcharlen(unsigned wc);
wchar_t				*ft_wstrdup(wchar_t const *s1);
wchar_t				*ft_wstrjoin(wchar_t *s1, wchar_t *s2);
wchar_t				*ft_wstrsub(wchar_t *s, unsigned start, unsigned len);
#endif
