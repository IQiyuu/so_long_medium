/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:31 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/23 15:44:37 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapconf	*init_map_struct(void)
{
	t_mapconf	*conf;

	conf = (t_mapconf *)malloc(sizeof(t_mapconf));
	if (!conf)
		return (NULL);
	conf->x_size = 0;
	conf->y_size = 0;
	conf->collectibles_nbr = 0;
	conf->player = NULL;
	conf->escap = 0;
	conf->map = NULL;
	conf->ennemies = NULL;
	return (conf);
}

t_list	*new_list(t_coords *act)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->coords = act;
	newlist->next = NULL;
	return (newlist);
}

t_coords	*new_coords(int x, int y)
{
	t_coords	*newcoords;

	newcoords = (t_coords *)malloc(sizeof(t_coords));
	if (!newcoords)
		return (0);
	newcoords->x = x;
	newcoords->y = y;
	return (newcoords);
}

t_player	*new_player(t_coords *coords)
{
	t_player	*newplayer;

	newplayer = (t_player *)malloc(sizeof(t_player));
	if (!newplayer)
		return (0);
	newplayer->coords = coords;
	newplayer->item_count = 0;
	newplayer->move_count = 0;
	return (newplayer);
}

int	*new_args(int col_max)
{
	int	*args;

	args = (int *)malloc(sizeof(int) * 3);
	if (!args)
		return (0);
	args[0] = 0;
	args[1] = 0;
	args[2] = col_max;
	return (args);
}
