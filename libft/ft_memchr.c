/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:52:33 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/04 16:24:49 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *memory, int c, size_t length)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)memory;
	while (length-- > 0)
		if (*(tmp++) == (unsigned char)c)
			return (tmp - 1);
	return (0);
}
