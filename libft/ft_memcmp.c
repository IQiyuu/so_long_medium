/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:55:11 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/04 19:14:27 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	unsigned char	*ptr_char1;
	unsigned char	*ptr_char2;

	ptr_char1 = (unsigned char *)ptr1;
	ptr_char2 = (unsigned char *)ptr2;
	if (size == 0)
		return (0);
	if (!ptr_char1 && !ptr_char2)
		return (0);
	while (size-- > 0)
	{
		if (*ptr_char1 != *ptr_char2)
			return (*ptr_char1 - *ptr_char2);
		ptr_char1++;
		ptr_char2++;
	}
	return (0);
}
