/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:22:10 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/04 16:16:54 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	if (s[size--] == (unsigned char)c)
		return ((char *)&s[size + 1]);
	while (size >= 0)
		if (s[size--] == (unsigned char)c)
			return ((char *)&s[size + 1]);
	return (0);
}
