/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:42:11 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 21:24:19 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texts_null(t_graphconf *g_conf, int start, int end)
{
	while (start < end)
		g_conf->texts[start++] = NULL;
}

void	imgs_null(t_graphconf *g_conf, int start, int end)
{
	while (start < end)
		g_conf->imgs[start++] = NULL;
}

void	delete_imgs(t_graphconf *g_conf, int start, int end)
{
	while (start < end)
		mlx_delete_image(g_conf->mlx, g_conf->imgs[start++]);
}

void	update_ppos_game(t_graphconf *g_conf, t_coords *act)
{
	g_conf->anims[0]->imgs[g_conf->anims[0]->index]->instances[0].x
		= (W_WIDTH - (g_conf->conf->x_size / 2) * 64)
		+ (act->x) * 64;
	g_conf->anims[0]->imgs[g_conf->anims[0]->index]->instances[0].y
		= W_HEIGHT - ((g_conf->conf->y_size / 2) * 64)
		+ ((act->y - 1) * 64) + 15;
}

void	update_ppos_menu(t_graphconf *g_conf, t_coords *act)
{
	if (act->x == 0)
	{
		g_conf->anims[0]->imgs[g_conf->anims[0]->index]->instances[0].x = 102;
		g_conf->anims[0]->imgs[g_conf->anims[0]->index]->instances[0].y = 97;
	}
	else
	{
		g_conf->anims[0]->imgs[g_conf->anims[0]->index]->instances[0].x
			= act->x * 340;
		g_conf->anims[0]->imgs[g_conf->anims[0]->index]->instances[0].y
			= (act->y + 1) * 320;
	}
}
