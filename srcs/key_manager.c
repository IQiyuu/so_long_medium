/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:56:59 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 19:22:55 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_manager(t_graphconf *g_conf, mlx_key_data_t keydata)
{
	int	end;

	end = 0;
	if (keydata.action != MLX_RELEASE && g_conf->anims[0]->enable)
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			end = move_left(g_conf);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			end = move_right(g_conf);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			end = move_down(g_conf);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			end = move_up(g_conf);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		end_game(g_conf, 0);
	if (keydata.key == MLX_KEY_M && !(g_conf->anims[3]->enable
			|| g_conf->anims[2]->enable))
		end_game_bis(g_conf, 3);
	return (end);
}
