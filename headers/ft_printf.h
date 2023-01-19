/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:46:08 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/10 19:46:46 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	conv_c(char c);
int	conv_int(int nbr, int ui);
int	conv_s(char *str);
int	conv_p(void *nbr);
int	conv_x(unsigned int nbr, int ui);
int	parser(char *str, va_list args);
int	intconv_manager(char c, va_list arg);
int	string_checker(char *str);
int	apply_conv(char c, va_list args);

#endif