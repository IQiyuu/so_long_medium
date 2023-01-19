/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:39:27 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 21:14:22 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\x1b[38;2;255;0;0m"
# define L_RED "\x1b[38;2;255;200;200m"
# define GREEN "\x1b[38;2;0;255;0m"
# define L_GREEN "\x1b[38;2;200;255;200m"
# define UINT_MAX 4294967296

typedef struct s_coords
{
	size_t	x;
	size_t	y;
}	t_coords;

typedef struct s_list	t_list;
struct s_list
{
	t_coords	*coords;
	t_list		*next;
};

size_t	ft_umin(size_t a, size_t b);
size_t	ft_umax(size_t a, size_t b);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t count);
void	ft_bzero(void *ptr, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strchr(const char *str, int searchedC);
char	*ft_strrchr(const char *str, int searchedC);
int		ft_strncmp(const char *first, const char *second, size_t length);
void	*ft_memchr(const void *memory, int searchedC, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
char	*ft_strnstr(const char *str1, const char *str2, size_t size);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t elemCount, size_t elemSize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set0);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_back(t_list **lst, void *content);
t_list	*ft_lstnew(void	*content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
int		ft_nbr_of(char *str, char c);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
void	ft_putnbr_ui_fd(unsigned int n, int fd);
int		ft_convertbase(unsigned long nbr, char *base_to);
int		ft_is_there(char *str1, char *str2, int size);

#endif