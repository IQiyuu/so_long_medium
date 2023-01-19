/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:53:08 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/28 14:31:26 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_graphconf *g_conf, int opt)
{
	t_player	*player;
	t_mapconf	*conf;

	conf = g_conf->conf;
	player = conf->player;
	if (g_conf->anims[0]->enable)
		system("killall afplay 2> /dev/null");
	if (opt == 0)
		end_game_bis(g_conf, 1);
	else if (opt == 1)
	{
		if (g_conf->anims[0]->enable)
			ft_printf(WIN, GREEN, L_GREEN, ft_strjoin("on ",
					g_conf->sel_map), player->move_count, '\n');
		white_fade(g_conf);
	}
	else if (opt == 2)
	{
		if (g_conf->anims[0]->enable)
			ft_printf(DEATH, RED, L_RED, ft_strjoin("on ",
					g_conf->sel_map), player->item_count,
				conf->collectibles_nbr, player->move_count, '\n');
		black_fade(g_conf);
	}
}

void	black_fade(t_graphconf *g_conf)
{
	mlx_image_t		*img;
	t_animframe		*anim;
	static int		cpt = DEATH_FRATE;
	static int		f_cpt = 0;

	if (f_cpt == 0)
	{
		g_conf->anims[1]->enable = 0;
		g_conf->anims[0]->enable = 0;
	}
	img = g_conf->imgs[9];
	if (cpt < DEATH_FRATE && f_cpt < 15)
		cpt++;
	else
	{
		cpt = 0;
		f_cpt++;
		mlx_image_to_window(g_conf->mlx, img, 0, 0);
	}
	anim = g_conf->anims[2];
	if (!anim->enable && f_cpt < 10)
		anim->enable = 1;
	else if (anim->enable)
		do_death_anim(anim, g_conf->mlx, g_conf, &f_cpt);
}

void	do_death_anim(t_animframe *anim, mlx_t *mlx, t_graphconf *g_conf,
	int *cpt)
{
	if (anim->count == 0 && anim->index == 0)
		mlx_image_to_window(mlx, anim->imgs[0],
			mlx->width / 2 - 32, mlx->height / 2 - 32);
	if (++anim->count == FRAME_RATE)
	{
		anim->count = 0;
		if (++anim->index < anim->size)
		{
			anim->imgs[anim->index - 1]->instances[0].enabled = 0;
			mlx_image_to_window(mlx, anim->imgs[anim->index],
				mlx->width / 2 - 32, mlx->height / 2 - 32);
		}
		if (anim->index > anim->size + 7)
		{
			free_conf(g_conf->conf);
			anim->imgs[6]->instances[0].enabled = 0;
			g_conf->anims[2]->enable = 0;
			*cpt = 0;
			system("killall afplay 2> /dev/null");
			win_menu(g_conf);
		}
	}
}

void	white_fade(t_graphconf *g_conf)
{
	mlx_image_t		*img;
	t_animframe		*anim;
	static int		cpt = DEATH_FRATE;
	static int		f_cpt = 0;

	if (f_cpt == 0)
	{
		system("afplay music/zelda.mp3 & disown");
		g_conf->anims[1]->enable = 0;
		g_conf->anims[0]->enable = 0;
	}
	img = g_conf->imgs[10];
	if (cpt < WIN_FRATE && f_cpt < 15)
		cpt++;
	else
	{
		cpt = 0;
		f_cpt++;
		mlx_image_to_window(g_conf->mlx, img, 0, 0);
	}
	anim = g_conf->anims[3];
	if (!anim->enable && f_cpt < 30)
		anim->enable = 1;
	else if (anim->enable)
		do_win_anim(anim, g_conf->mlx, g_conf, &f_cpt);
}

void	do_win_anim(t_animframe *anim, mlx_t *mlx, t_graphconf *g_conf,
			int *cpt)
{
	if (anim->count == 0 && anim->index == 0)
		mlx_image_to_window(mlx, anim->imgs[0],
			mlx->width / 2 - 32, mlx->height / 2 - 32);
	if (++anim->count == FRAME_RATE)
	{
		anim->count = 0;
		if (++anim->index < anim->size)
		{
			anim->imgs[anim->index - 1]->instances[0].enabled = 0;
			mlx_image_to_window(mlx, anim->imgs[anim->index],
				mlx->width / 2 - 32, mlx->height / 2 - 32);
		}
		if (anim->index > anim->size + 5)
		{
			free_conf(g_conf->conf);
			if (!ft_strncmp(g_conf->sel_map, ft_strjoin(ft_strjoin("maps/lvl",
							ft_itoa(g_conf->menu->unlocked_lvls)), ".ber"), 13))
			g_conf->menu->unlocked_lvls = ft_min(g_conf->menu->unlocked_lvls
						+ 1, 10);
			anim->imgs[5]->instances[0].enabled = 0;
			g_conf->anims[3]->enable = 0;
			*cpt = 0;
			win_menu(g_conf);
		}
	}
}
