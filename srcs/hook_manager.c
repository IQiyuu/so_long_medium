/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:15:52 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 13:45:52 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	menukey_manager(t_graphconf *g_conf, mlx_key_data_t keydata)
{
	if (keydata.action == MLX_PRESS && !g_conf->in_game)
	{
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			menumove_left(g_conf);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			menumove_right(g_conf);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			menumove_down(g_conf);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			menumove_up(g_conf);
		if (keydata.key == MLX_KEY_ENTER)
		{
			refresh_win(g_conf);
			win_game(g_conf);
		}
	}
	return (0);
}
