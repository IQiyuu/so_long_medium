/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:16:37 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/08 14:47:14 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	cpt;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		if (!res)
			return (0);
		res[0] = 0;
		return (res);
	}
	res = malloc(sizeof(char) * (ft_umin(ft_strlen(s) - start, len) + 1));
	if (!res)
		return (0);
	cpt = -1;
	while (++cpt < ft_umin(ft_strlen(s) - start, len) && s[cpt])
		res[cpt] = s[start + cpt];
	res[cpt] = 0;
	return (res);
}
