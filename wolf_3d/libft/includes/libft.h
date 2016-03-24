/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:36:58 by acollet           #+#    #+#             */
/*   Updated: 2015/03/27 17:54:22 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmove(char **str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
int					ft_strpos(const char *str, int c);
void				ft_strconcat(char **s1, const char *s2);
char				*ft_strtoupper(char *s);
char				*ft_strtolower(char *s);

double				ft_ceil(double x);
double				ft_fabs(double x);
double				ft_floor(double x);
double				ft_pow(double x, double y);
double				ft_sqrt(double x);
void				ft_swapfloat(float *f1, float *f2);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);

int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);

int					ft_atoi(const char *str);
char				*ft_htoa(unsigned long n, int caps);
char				*ft_itoa(int n);
char				*ft_otoa(unsigned long n);
char				*ft_ntoa(unsigned long n, int base, int caps);
int					ft_tolower(int c);
int					ft_toupper(int c);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddqueue(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstinsert(t_list *list, t_list	**bef, t_list **node);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstlast(t_list *alst);
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstprevious(t_list *head, t_list *srch);
void				ft_lstsort(t_list **lst, int (*f)(t_list*, t_list*));
int					ft_lstswap(t_list **head, t_list **node1, t_list **node2);
void				ft_lstrevert(t_list **lst);
#endif
