/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:11:43 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/04 18:42:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_in(char searched, const char *set)
{
	while (*set)
		if (*(set++) == searched)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char*set)
{
	int		total_size;
	char	*res;
	int		cpt;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	cpt = 0;
	total_size = ft_strlen(s1);
	while (s1[cpt] && is_in(s1[cpt], set))
		cpt++;
	while (is_in(s1[total_size - 1], set) && total_size > 0)
		total_size--;
	res = (char *)malloc(sizeof(char) * (ft_max(0, total_size - cpt) + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, &(s1[cpt]), (total_size - cpt) + 1);
	return (res);
}
