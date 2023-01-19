/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:23:39 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/22 16:28:02 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst || del)
	{
		if (*lst)
		{
			while ((*lst)->next)
			{
				tmp = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = tmp;
			}
		}
	}
}
