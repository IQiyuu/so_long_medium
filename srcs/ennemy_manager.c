/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:54:48 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 21:45:31 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graph_ennemies_bis(t_graphconf *g_conf, size_t *cpt)
{
	mlx_image_t	*img;

	while (++cpt[2] < 9)
	{
		img = g_conf->anims[1]->imgs[cpt[2]];
		cpt[3] = mlx_image_to_window(g_conf->mlx, img,
				W_WIDTH - ((g_conf->conf->x_size / 2) * 64)
				+ (cpt[1] * 64),
				W_HEIGHT - ((g_conf->conf->y_size / 2) * 64)
				+ ((cpt[0] - 1) * 64) + 15);
		if (cpt[2] != 0)
			img->instances[cpt[3]].enabled = 0;
	}
}

void	apply_ennemies_moves(t_list *ennemy, t_coords *new_coords,
			t_graphconf *g_conf, int cpt)
{
	free(ennemy->coords);
	ennemy->coords = new_coords;
	graph_move_ennemy(ennemy->coords,
		g_conf->anims[1]->imgs[g_conf->anims[1]->index], cpt,
		g_conf);
}

void	random_move(int x, t_list *ennemies, t_graphconf *g_conf, int cpt)
{
	char		**map;
	t_coords	*act;

	map = g_conf->conf->map;
	act = ennemies->coords;
	x = rand() % 4;
	if (--x < 0 && (ft_strchr("E1", map[act->y][act->x + 1]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x + 1, act->y),
			g_conf, cpt);
	else if (--x < 0 && (ft_strchr("E1", map[act->y][act->x - 1]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x - 1, act->y),
			g_conf, cpt);
	else if (--x < 0 && (ft_strchr("E1", map[act->y + 1][act->x]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x, act->y + 1),
			g_conf, cpt);
	else if (--x < 0 && (ft_strchr("E1", map[act->y - 1][act->x]) == -1))
		apply_ennemies_moves(ennemies, new_coords(act->x, act->y - 1),
			g_conf, cpt);
}

void	gen_ennemies_moves(t_graphconf *g_conf)
{
	t_list		*ennemies;
	t_coords	*act;
	int			cpt;

	cpt = 0;
	ennemies = g_conf->conf->ennemies;
	while (ennemies)
	{
		act = ennemies->coords;
		if (nbr_move_pos(g_conf->conf->map, ennemies->coords) > 0)
			random_move(0, ennemies, g_conf, cpt);
		cpt++;
		ennemies = ennemies->next;
	}
}

int	ennemy_on_player(t_graphconf *g_conf)
{
	t_list	*ennemy;

	ennemy = g_conf->conf->ennemies;
	while (ennemy)
	{
		if (same_coords(ennemy->coords, g_conf->conf->player->coords, 0, 0))
			return (1);
		ennemy = ennemy->next;
	}
	return (0);
}
