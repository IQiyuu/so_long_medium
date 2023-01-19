/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:03:28 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/09 20:29:08 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	minus;

	res = 0;
	minus = 1;
	while (*str == 32 || *str == 9 || *str == 10 || *str == 12 || *str == 13
		|| *str == 11)
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			minus = -1;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *(str++) - '0';
	return (res * minus);
}
