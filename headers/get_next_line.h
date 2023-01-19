/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:38:06 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/13 13:07:14 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		check_isnl(char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *buf, int fd);
void	ft_endingbuf(char *str);
char	*ft_clearbuf(char *str, char *res);
char	*ft_strcat(char *src, char *dest);
char	*ft_strdup_untilnl(char *str, int boolnl);

#endif
