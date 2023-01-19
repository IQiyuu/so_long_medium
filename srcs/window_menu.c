/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:43:31 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/28 17:48:22 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_way_bis(size_t cpt, int cpt2, t_graphconf *g_conf)
{
	cpt = 330;
	if (g_conf->menu->unlocked_lvls >= 6)
	{
		while (cpt++ < 665)
		{
			cpt2 = 0;
			while (cpt2 < 21)
				mlx_put_pixel(g_conf->imgs[1], 1730 + cpt2++, cpt, 0xEF8E30FF);
		}
	}
}

void	init_way(t_graphconf *g_conf)
{
	size_t	cpt;
	int		cpt2;

	cpt = 80;
	while (cpt++ < 1920)
	{
		cpt2 = 0;
		if (g_conf->perso && cpt < 310)
			while (cpt2 < 29)
				mlx_put_pixel(g_conf->imgs[1], cpt + 90,
					cpt2++ + cpt + 70, 0xEF8E30FF);
		if (g_conf->menu->unlocked_lvls > cpt / 330
			&& cpt < 1600 && cpt > 330)
			while (cpt2 < 21)
				mlx_put_pixel(g_conf->imgs[1], cpt + 90,
					cpt2++ + 365, 0xEF8E30FF);
		cpt2 = 0;
		if (ft_umax(g_conf->menu->unlocked_lvls, 6) - 6 > cpt / 360
			&& cpt < 1800)
			while (cpt2 < 21)
				mlx_put_pixel(g_conf->imgs[1], 1750 - cpt + 58,
					cpt2++ + 685, 0xEF8E30FF);
	}
	init_way_bis(cpt, cpt2, g_conf);
}

void	init_round_bis(t_graphconf *g_conf, size_t cpt)
{
	size_t		cpt2;

	cpt2 = cpt;
	while (--cpt > 0)
	{
		if (cpt2++ <= g_conf->menu->unlocked_lvls)
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[3], 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 2) * 320);
		else
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[2], 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 2) * 320);
	}
}

void	init_menuwin(t_graphconf *g_conf)
{
	size_t		cpt;

	cpt = 0;
	mlx_image_to_window(g_conf->mlx, g_conf->imgs[1], 0, 0);
	if (g_conf->perso != NULL)
		mlx_image_to_window(g_conf->mlx, g_conf->imgs[3], 95, 95);
	else
		mlx_image_to_window(g_conf->mlx, g_conf->imgs[2], 95, 95);
	while (++cpt < 6)
	{
		if (cpt <= g_conf->menu->unlocked_lvls)
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[3], 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 1
					+ (cpt / 6)) * 320);
		else
			mlx_image_to_window(g_conf->mlx, g_conf->imgs[2], 334
				* cpt + (cpt * 3), (g_conf->conf->y_size + 1
					+ (cpt / 6)) * 320);
	}
	init_round_bis(g_conf, cpt);
	init_way(g_conf);
	system("afplay music/wii.mp3 & disown");
}

void	win_menu(t_graphconf *g_conf)
{
	g_conf->in_game = 0;
	system("killall afplay 2> /dev/null");
	g_conf->conf = init_map_struct();
	g_conf->conf->player = init_menuplayer(g_conf);
	update_ppos_menu(g_conf, g_conf->conf->player->coords);
	delete_imgs(g_conf, 1, 13);
	g_conf->anim_nbr--;
	free_anim(g_conf->mlx, g_conf->anims[1]);
	free_anim(g_conf->mlx, g_conf->anims[2]);
	free_anim(g_conf->mlx, g_conf->anims[3]);
	g_conf->anims[1] = NULL;
	g_conf->anims[2] = NULL;
	g_conf->anims[3] = NULL;
	g_conf->anims[0]->enable = 1;
	init_img(g_conf->mlx, g_conf);
	init_menuwin(g_conf);
	update_player_framez(g_conf, g_conf->imgs[3]
		->instances[g_conf->menu->unlocked_lvls - 1].z + 1, 1);
}
