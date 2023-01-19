/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:05:55 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/02 18:23:32 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*tmp_src;
	char	*tmp_dest;

	if (!dest && !src)
		return (0);
	tmp_src = (char *)src;
	tmp_dest = (char *)dest;
	if (size == 0)
		return (dest);
	while (size-- > 0)
		*(tmp_dest++) = *(tmp_src++);
	return (dest);
}
