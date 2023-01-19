/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:14:52 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/13 22:01:32 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		src_size;

	src_size = ft_strlen((char *)src);
	if (size == 0)
		return (src_size);
	while (--size > 0 && *src)
		*(dest++) = *(src++);
	*dest = 0;
	return (src_size);
}
