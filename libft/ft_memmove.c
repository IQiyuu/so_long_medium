/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:11:28 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/03 02:00:14 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*char_s;
	char		*char_d;

	if (!dest && !src)
		return (0);
	char_s = (char *)src;
	char_d = (char *)dest;
	if (char_d > char_s)
		while (size-- > 0)
			char_d[size] = char_s[size];
	else
		while (size-- > 0)
			*(char_d++) = *(char_s++);
	return (dest);
}
