/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:10:24 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/03 15:49:13 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elemCount, size_t elemSize)
{
	void	*located;

	located = malloc(elemCount * elemSize);
	if (!located)
		return (0);
	ft_bzero(located, (elemCount * elemSize));
	return (located);
}
