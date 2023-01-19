/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:35:41 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/19 15:16:08 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_conv(char c, va_list args)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return (conv_int((int)va_arg(args, int), (c == 'u')));
	if (c == 's')
		return (conv_s((char *)va_arg(args, char *)));
	if (c == 'c')
		return (conv_c((unsigned char)va_arg(args, unsigned int)));
	if (c == '%')
		return (conv_c('%'));
	if (c == 'x')
		return (conv_x((unsigned int)va_arg(args, int), 0));
	if (c == 'X')
		return (conv_x((unsigned int)va_arg(args, int), 1));
	if (c == 'p')
		return (conv_p((void *)va_arg(args, void *)));
	return (0);
}

int	string_checker(char *str)
{
	int	cpt;

	cpt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (!(*(str + 1) == 's' || *(str + 1) == '%' || *(str + 1) == 'd'
					|| *(str + 1) == 'c' || *(str + 1) == 'x'
					|| *(str + 1) == 'X' || *(str + 1) == 'i'
					|| *(str + 1) == 'u' || *(str + 1) == 'p'))
				return (-1);
			str++;
		}
		str++;
	}
	return (cpt);
}

int	parser(char *str, va_list args)
{
	int	cpt;
	int	size;
	int	error;

	if (string_checker(str) == -1)
		return (-1);
	size = 0;
	cpt = 0;
	error = 0;
	while (str[cpt])
	{
		if (str[cpt] == '%')
		{
			size += apply_conv(str[cpt + 1], args);
			cpt += 2;
		}
		else
			ft_putchar_fd(str[cpt++], 1);
		size++;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;

	va_start(args, str);
	res = parser((char *)str, args);
	va_end(args);
	return (res);
}
