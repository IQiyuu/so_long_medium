/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:18 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 21:50:50 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_win(t_graphconf *g_conf, mlx_t *mlx, size_t cpt)
{	
	size_t	cpt2;

	while (++cpt < g_conf->conf->y_size && g_conf->conf->map[cpt])
	{
		cpt2 = -1;
		while (++cpt2 < g_conf->conf->x_size && g_conf->conf->map[cpt][cpt2])
		{
			mlx_image_to_window(mlx, g_conf->imgs[4],
				(W_WIDTH - ((g_conf->conf->x_size / 2 - cpt2) * 64)),
				(W_HEIGHT - ((g_conf->conf->y_size / 2 - cpt + 1) * 64)));
			if (g_conf->conf->map[cpt][cpt2] == '1')
				mlx_image_to_window(mlx, g_conf->imgs[5],
					(W_WIDTH - ((g_conf->conf->x_size / 2 - cpt2) * 64)),
					(W_HEIGHT - ((g_conf->conf->y_size / 2 - cpt + 1) * 64)));
			if (g_conf->conf->map[cpt][cpt2] == 'C')
				mlx_image_to_window(mlx, g_conf->imgs[7],
					(W_WIDTH - ((g_conf->conf->x_size / 2 - cpt2) * 64)),
					(W_HEIGHT - ((g_conf->conf->y_size / 2 - cpt +1) * 64)));
		}
	}
	update_player_framez(g_conf, 0, 0);
	return (1);
}

void	update_player_framez(t_graphconf *g_conf, int ref, int rd)
{
	int	cpt;

	if (rd)
	{
		cpt = 0;
		while (cpt < 6)
		{
			g_conf->anims[0]->imgs[cpt]->instances[0].z
				= ref + 1;
			cpt++;
		}
	}
	else
		mlx_image_to_window(g_conf->mlx, g_conf->imgs[6],
			(W_WIDTH - ((g_conf->conf->x_size / 2
						- g_conf->conf->escap->x) * 64) - 12),
			(W_HEIGHT - ((g_conf->conf->y_size / 2
						- g_conf->conf->escap->y + 1) * 64) - 12));
}

void	init_gameimg(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->texts[4] = mlx_load_png(ft_strjoin(IMG_PATH, "grass.png"));
	g_conf->texts[5] = mlx_load_png(ft_strjoin(IMG_PATH, "tree.png"));
	g_conf->texts[6] = mlx_load_png(ft_strjoin(IMG_PATH, "house.png"));
	g_conf->texts[7] = mlx_load_png(ft_strjoin(IMG_PATH, "paper.png"));
	g_conf->texts[8] = mlx_load_png(ft_strjoin(IMG_PATH, "slime/slime0.png"));
	g_conf->texts[9] = mlx_load_png(ft_strjoin(IMG_PATH, "black_bg.png"));
	g_conf->texts[10] = mlx_load_png(ft_strjoin(IMG_PATH, "white_bg.png"));
	check_text_error(g_conf, 10);
	g_conf->imgs[4] = mlx_texture_to_image(mlx, g_conf->texts[4]);
	g_conf->imgs[5] = mlx_texture_to_image(mlx, g_conf->texts[5]);
	g_conf->imgs[6] = mlx_texture_to_image(mlx, g_conf->texts[6]);
	g_conf->imgs[7] = mlx_texture_to_image(mlx, g_conf->texts[7]);
	g_conf->imgs[8] = mlx_texture_to_image(mlx, g_conf->texts[8]);
	g_conf->imgs[9] = mlx_texture_to_image(mlx, g_conf->texts[9]);
	g_conf->imgs[10] = mlx_texture_to_image(g_conf->mlx, g_conf->texts[10]);
}

void	init_gameanim(mlx_t *mlx, t_graphconf *g_conf)
{
	g_conf->anims[2] = NULL;
	g_conf->anims[3] = NULL;
	g_conf->anims[1] = new_animation("slime/slime", 9, mlx);
	if (!g_conf->anims[1])
		frame_error(g_conf);
	g_conf->anims[2] = new_animation("death/death", 7, mlx);
	if (!g_conf->anims[2])
		frame_error(g_conf);
	g_conf->anims[3] = new_animation("win/win", 6, mlx);
	if (!g_conf->anims[3])
		frame_error(g_conf);
	g_conf->anims[1]->enable = 1;
	g_conf->anim_nbr++;
}

int	win_game(t_graphconf *g_conf)
{
	system("killall afplay");
	system("afplay music/zelda.mp3 & disown");
	g_conf->in_game = 1;
	free(g_conf->conf);
	g_conf->conf = init_map(g_conf->sel_map);
	if (!g_conf->conf)
		end_game_bis(g_conf, 0);
	update_ppos_game(g_conf, g_conf->conf->player->coords);
	free(g_conf->i_str);
	free(g_conf->m_str);
	g_conf->i_str
		= ft_strjoin("Items : 0/", ft_itoa(g_conf->conf->collectibles_nbr));
	g_conf->m_str = ft_strdup("Moves : 0");
	g_conf->imgs[1]->enabled = 0;
	init_gameimg(g_conf->mlx, g_conf);
	init_gameanim(g_conf->mlx, g_conf);
	fill_win(g_conf, g_conf->mlx, -1);
	init_graph_enemies(g_conf);
	frame_update_bis(g_conf);
	g_conf->imgs[11] = mlx_put_string(g_conf->mlx, g_conf->m_str, 10, 0);
	g_conf->imgs[12] = mlx_put_string(g_conf->mlx, g_conf->i_str,
			W_WIDTH * 2 - 124, 0);
	return (EXIT_SUCCESS);
}
