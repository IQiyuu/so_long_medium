/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:20:33 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/04 15:18:47 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	cpt;
	size_t	cpt2;

	if (size == 0 && (!src || !dest))
		return (0);
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	cpt = ft_strlen(dest);
	cpt2 = 0;
	while (src[cpt2] != 0 && cpt + 1 < size)
		dest[cpt++] = src[cpt2++];
	dest[cpt] = 0;
	return (ft_strlen(dest) + ft_strlen(&src[cpt2]));
}
