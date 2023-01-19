/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:12:51 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/08 23:25:16 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		cpt;
	char	*res;
	char	*ret;

	if (!s1)
		return (0);
	cpt = ft_strlen(s1);
	res = malloc(sizeof(char) * (cpt + 1));
	if (!res)
		return (0);
	ret = res;
	while (cpt-- > 0)
		*(res++) = *(s1++);
	*res = 0;
	return (ret);
}
