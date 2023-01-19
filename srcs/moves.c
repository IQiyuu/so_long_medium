/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:33:39 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 15:42:54 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* g_imgs => 0 : sol / 1 : murs / 2 : exit / 3 : player / 4 : items */

int	apply_move(t_graphconf *g_conf)
{
	size_t		*m_count;
	size_t		p_y;
	size_t		p_x;
	t_mapconf	*conf;

	conf = g_conf->conf;
	p_y = conf->player->coords->y;
	p_x = conf->player->coords->x;
	m_count = &g_conf->conf->player->move_count;
	graph_move_player(conf->player->coords, g_conf->anims[0]
		->imgs[g_conf->anims[0]->index], conf->x_size, conf->y_size);
	graph_refresh_mcount(g_conf);
	if (conf->map[p_y][p_x] == 'E' &&
		conf->player->item_count == conf->collectibles_nbr)
		return (1);
	else if (conf->map[p_y][p_x] == 'C')
	{
		graph_dispawn_item(conf->player->coords, g_conf->imgs[7], conf->map);
		conf->player->item_count++;
		conf->map[p_y][p_x] = 'c';
		graph_refresh_icount(g_conf);
	}
	else if (!ennemy_on_player(g_conf))
		gen_ennemies_moves(g_conf);
	return (0);
}

int	move_left(t_graphconf *g_conf)
{
	t_coords	*tmp;
	t_mapconf	*conf;
	t_player	*ply;

	conf = g_conf->conf;
	ply = conf->player;
	if (conf->map[ply->coords->y][ply->coords->x - 1] != '1')
	{
		tmp = ply->coords;
		ply->coords = new_coords(tmp->x - 1, tmp->y);
		free(tmp);
		return (apply_move(g_conf));
	}
	return (0);
}

int	move_right(t_graphconf *g_conf)
{
	t_coords	*tmp;
	t_mapconf	*conf;
	t_player	*ply;

	conf = g_conf->conf;
	ply = conf->player;
	if (conf->map[ply->coords->y][ply->coords->x + 1] != '1')
	{
		tmp = ply->coords;
		ply->coords = new_coords(tmp->x + 1, tmp->y);
		free(tmp);
		return (apply_move(g_conf));
	}
	return (0);
}

int	move_up(t_graphconf *g_conf)
{
	t_coords	*tmp;
	t_mapconf	*conf;
	t_player	*ply;

	conf = g_conf->conf;
	ply = conf->player;
	if (conf->map[ply->coords->y - 1][ply->coords->x] != '1')
	{
		tmp = ply->coords;
		ply->coords = new_coords(tmp->x, tmp->y - 1);
		free(tmp);
		return (apply_move(g_conf));
	}
	return (0);
}

int	move_down(t_graphconf *g_conf)
{
	t_coords	*tmp;
	t_mapconf	*conf;
	t_player	*ply;

	conf = g_conf->conf;
	ply = conf->player;
	if (conf->map[ply->coords->y + 1][ply->coords->x] != '1')
	{
		tmp = ply->coords;
		ply->coords = new_coords(tmp->x, tmp->y + 1);
		free(tmp);
		return (apply_move(g_conf));
	}
	return (0);
}
