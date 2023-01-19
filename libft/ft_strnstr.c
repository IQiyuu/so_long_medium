/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:59:14 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/21 12:20:49 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_there(char *str1, char *str2, int size)
{
	int	cpt;

	cpt = 0;
	while (str1[cpt] && str2[cpt] && size-- > 0)
	{
		if (str1[cpt] == str2[cpt])
			return (1);
		cpt++;
	}
	return (0);
}

char	*ft_strnstr(const char *str1, const char *str2, size_t size)
{
	int	cpt;

	if (*str2 == 0 || str1 == str2)
		return ((char *)str1);
	if (size == 0)
		return (0);
	cpt = 0;
	size = ft_umin(ft_strlen(str1), size);
	while (str1[cpt] && size-- > 0)
		if (str1[cpt++] == *str2)
			if (ft_is_there((char *)&(str1[cpt - 1]), (char *)str2, size + 1))
				return ((char *)&str1[cpt - 1]);
	return (0);
}
