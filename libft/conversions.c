/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:46:24 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/23 17:16:54 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_int(int nbr, int ui)
{
	unsigned int	n;

	n = 0;
	if (ui)
	{
		if (nbr < 0)
			n = UINT_MAX + nbr;
		else
			n = nbr;
		ft_putnbr_ui_fd(n, 1);
		return (0);
	}
	ft_putnbr_fd(nbr, 1);
	return (0);
}

int	conv_s(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	ft_putstr_fd("(null)", 1);
	return (6);
}

int	conv_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	conv_x(unsigned int nbr, int up)
{
	if (up)
		return (ft_convertbase(nbr, "0123456789ABCDEF"));
	return (ft_convertbase(nbr, "0123456789abcdef"));
}

int	conv_p(void *nbr)
{
	ft_putstr_fd("0x", 1);
	return (ft_convertbase((unsigned long)nbr, "0123456789abcdef") + 2);
}
