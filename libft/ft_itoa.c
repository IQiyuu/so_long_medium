/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:23:59 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/03 15:49:04 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	len(int n)
{
	int	cpt;

	cpt = 0;
	if (n == -2147483648)
	{
		cpt++;
		n /= 10;
	}
	if (n < 0)
		n /= -1;
	while (n > 9)
	{
		cpt++;
		n /= 10;
	}
	return (cpt + 1);
}

char	*fct_jsp(int n, char *res, int cpt)
{
	while (n > 9)
	{
		res[cpt--] = n % 10 + '0';
		n /= 10;
	}
	res[cpt] = n + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		cpt;
	int		minus;

	minus = 0;
	if (n < 0)
		minus++;
	res = (char *)malloc(sizeof(char) * (len(n) + minus + 1));
	if (!res)
		return (0);
	cpt = len(n) + minus;
	res[cpt--] = 0;
	if (n == -2147483648)
	{
		res[cpt--] = 8 + '0';
		n /= 10;
	}
	if (n < 0)
	{
		res[0] = '-';
		n /= -1;
	}
	return (fct_jsp(n, res, cpt));
}
