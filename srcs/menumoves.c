/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menumoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:26:58 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 22:31:13 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	apply_menumove(t_graphconf *g_conf)
{
	mlx_image_t	*img;

	img = g_conf->anims[0]->imgs[g_conf->anims[0]->index];
	if (g_conf->conf->player->coords->x == 0)
	{
		img->instances[0].x = 102;
		img->instances[0].y = 97;
	}
	else
	{
		img->instances[0].x = (g_conf->conf->player->coords->x * 340);
		img->instances[0].y = ((g_conf->conf->player->coords->y + 1) * 320);
	}
	return (EXIT_SUCCESS);
}

int	menumove_left(t_graphconf *g_conf)
{
	t_coords	*act;
	t_coords	*tmp;

	act = g_conf->conf->player->coords;
	if ((act->y == 1 && ((act->x > (5 - g_conf->menu->unlocked_lvls % 6)
					&& g_conf->perso)
				|| (act->x > (5 - g_conf->menu->unlocked_lvls % 6)
					&& act->x > 1)))
		|| (g_conf->perso && act->x >= 1 && act->y == 0)
		|| (!g_conf->perso && act->x > 1 && act->y == 0))
	{
		tmp = g_conf->conf->player->coords;
		g_conf->conf->player->coords = new_coords(tmp->x - 1, tmp->y);
		free(tmp);
		return (apply_menumove(g_conf));
	}
	return (EXIT_SUCCESS);
}

int	menumove_down(t_graphconf *g_conf)
{
	t_coords	*act;
	t_coords	*tmp;

	act = g_conf->conf->player->coords;
	if ((act->x == 0 && act->y == 1 && g_conf->menu->unlocked_lvls / 5 >= 2)
		|| (act->x == 5 && act->y == 0 && g_conf->menu->unlocked_lvls / 5 >= 1))
	{
		tmp = g_conf->conf->player->coords;
		g_conf->conf->player->coords = new_coords(tmp->x, tmp->y + 1);
		free(tmp);
		return (apply_menumove(g_conf));
	}
	return (EXIT_SUCCESS);
}

int	menumove_up(t_graphconf *g_conf)
{
	t_coords	*act;
	t_coords	*tmp;

	act = g_conf->conf->player->coords;
	if ((act->x == 0 && act->y == 2)
		|| (act->x == 5 && act->y == 1))
	{
		tmp = g_conf->conf->player->coords;
		g_conf->conf->player->coords = new_coords(tmp->x, tmp->y - 1);
		free(tmp);
		return (apply_menumove(g_conf));
	}
	return (EXIT_SUCCESS);
}

int	menumove_right(t_graphconf *g_conf)
{
	t_coords	*act;
	t_coords	*tmp;

	act = g_conf->conf->player->coords;
	if (((act->y == 0 && act->x < g_conf->menu->unlocked_lvls)
			|| (act->y == 1 && act->x < (5 - g_conf->menu->unlocked_lvls)))
		&& act->x < 5)
	{
		tmp = g_conf->conf->player->coords;
		g_conf->conf->player->coords = new_coords(tmp->x + 1, tmp->y);
		free(tmp);
		return (apply_menumove(g_conf));
	}
	return (EXIT_SUCCESS);
}
