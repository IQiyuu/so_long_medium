/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:00:10 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/03 15:48:59 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	int		cpt;
	char	*tmp;

	tmp = ptr;
	cpt = 0;
	count++;
	while (--count > 0)
		tmp[cpt++] = value;
	return (ptr);
}
