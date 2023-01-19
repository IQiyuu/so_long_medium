/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:04 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/25 20:34:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(char *str)
{
	if (ft_strrchr(str, '.') == NULL)
	{
		ft_printf("no file extension found, use a .ber file");
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(ft_strrchr(str, '.'), ".ber", 4) != 0)
	{
		ft_printf("bad extension, %s don't work instead use .ber",
			ft_strrchr(str, '.'));
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	char	*filename;

	srand(time(NULL));
	if (argc == 2)
	{
		check_file_name(argv[1]);
		filename = ft_strjoin(MAP_PATH, argv[1]);
	}
	else
		filename = NULL;
	win_init(filename);
	return (EXIT_SUCCESS);
}
