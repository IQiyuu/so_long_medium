/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:19:39 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/21 12:39:35 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	int	cpt;

	cpt = 0;
	while (s[cpt])
		if (s[cpt++] == (unsigned char)c)
			return (cpt - 1);
	if (s[cpt] == (unsigned char)c)
		return (cpt);
	return (-1);
}
