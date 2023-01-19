/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:04:32 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 19:37:42 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_way_init(t_mapconf *conf)
{
	int			*args;
	t_list		*closed_lst;
	int			valid_map;

	closed_lst = new_list(conf->player->coords);
	args = new_args(conf->collectibles_nbr);
	valid_map = find_way(conf->map, conf->player->coords, &closed_lst, args);
	ft_lstclear(&(closed_lst->next->next), &free);
	free(closed_lst);
	free(args);
	return (valid_map);
}

int	find_way(char **map, t_coords *act, t_list **closed, int *args)
{
	int	end;

	ft_lstadd_back(closed, act);
	args[0] = ((map[act->y][act->x] == 'E') || args[0]);
	args[1] += (map[act->y][act->x] == 'C');
	end = (args[0] == 1 && args[1] == args[2]);
	if ((!end && map[act->y][act->x + 1] != '1'
		&& map[act->y][act->x + 1] != 'S' && !is_in(*closed, act, 1, 0)))
		end = find_way(map, new_coords(act->x + 1, act->y), closed, args);
	if ((!end && map[act->y + 1][act->x] != '1'
		&& map[act->y + 1][act->x] != 'S' && !is_in(*closed, act, 0, 1)))
		end = find_way(map, new_coords(act->x, act->y + 1), closed, args);
	if ((!end && map[act->y - 1][act->x] != '1'
		&& map[act->y - 1][act->x] != 'S' && !is_in(*closed, act, 0, -1)))
		end = find_way(map, new_coords(act->x, act->y - 1), closed, args);
	if ((!end && map[act->y][act->x - 1] != '1'
		&& map[act->y][act->x - 1] != 'S' && !is_in(*closed, act, -1, 0)))
		end = find_way(map, new_coords(act->x - 1, act->y), closed, args);
	return (end);
}
