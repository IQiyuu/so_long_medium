/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:42 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/28 14:31:42 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_update_bis(t_graphconf *g_conf)
{
	if (ft_lstsize(g_conf->conf->ennemies) > 0)
		update_player_framez(g_conf, g_conf->anims[1]->imgs[8]
			->instances[ft_lstsize(g_conf->conf->ennemies) - 1].z, 1);
	else
		update_player_framez(g_conf, g_conf->imgs[6]->instances[0].z, 1);
}

t_player	*init_menuplayer(t_graphconf *g_conf)
{
	if (ft_strnstr(g_conf->sel_map, "lvl", 9) != NULL)
	{
		if (ft_atoi(&ft_strnstr(g_conf->sel_map, "lvl", 9)[3]) <= 5)
			return (new_player(new_coords(ft_atoi(
							&ft_strnstr(g_conf->sel_map, "lvl", 9)[3]), 0)));
		else if (ft_atoi(&ft_strnstr(g_conf->sel_map, "lvl", 9)[3]) <= 10)
			return (new_player(new_coords(11
						- ft_atoi(&ft_strnstr(g_conf->sel_map,
								"lvl", 9)[3]), 1)));
	}
	return (new_player(new_coords(0, 0)));
}
