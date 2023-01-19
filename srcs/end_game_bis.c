/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:26:46 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 21:32:48 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game_manager(t_graphconf *g_conf)
{
	end_game_bis(g_conf, 2);
}

void	end_game_bis(t_graphconf *g_conf, int opt)
{
	if (opt == 0)
	{
		ft_printf(MERROR);
		free_gconf(g_conf);
		exit(MLX_SUCCESS);
	}
	if (opt == 1)
	{
		ft_printf(ESC);
		free_gconf(g_conf);
		exit(MLX_SUCCESS);
	}
	if (opt == 2)
	{
		ft_printf(CROSS);
		free_gconf(g_conf);
		exit(MLX_SUCCESS);
	}
	if (opt == 3)
	{
		system("killall afplay 2> /dev/null");
		ft_printf(MESC);
		win_menu(g_conf);
	}
}
