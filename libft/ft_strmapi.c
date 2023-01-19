/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:18:15 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/03 15:45:40 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		cpt;
	char	*res;

	cpt = 0;
	while (s[cpt++])
		;
	res = (char *)malloc(sizeof(char) * cpt);
	if (!res)
		return (0);
	cpt = 0;
	while (s[cpt])
	{
		res[cpt] = f(cpt, s[cpt]);
		cpt++;
	}
	res[cpt] = 0;
	return (res);
}
