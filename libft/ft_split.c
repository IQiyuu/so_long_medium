/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:35 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/11/03 14:45:23 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_of_words(char *str, char c)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (str[index])
	{
		while (str[index] == c)
			index++;
		if (!(str[index] == c) && str[index])
		{
			count++;
			while (!(str[index] == c) && str[index])
				index++;
		}
	}
	return (count);
}

char	*get_next_word(int *index, char *str, char c)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (str[*index] == c)
		(*index)++;
	while (!(str[*index + len] == c) && str[*index + len])
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = str[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		size;
	int		cpt;
	int		index;

	size = nb_of_words((char *)str, c);
	res = (char **)malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	cpt = 0;
	index = 0;
	while (cpt < size)
		res[cpt++] = get_next_word(&index, (char *)str, c);
	res[cpt] = 0;
	return (res);
}
