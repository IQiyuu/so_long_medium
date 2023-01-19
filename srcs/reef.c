/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reef.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:49:50 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 16:45:55 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapconf	*free_conf(t_mapconf *conf)
{
	size_t	cpt;

	if (conf != NULL)
	{
		cpt = 0;
		if (conf->map != NULL)
			while (conf->map[cpt] != NULL)
				free(conf->map[cpt++]);
		if (conf->player != NULL)
			free_player(conf->player);
		if (conf->escap)
			free(conf->escap);
		free(conf);
		if (conf->ennemies)
			ft_lstclear(&conf->ennemies, &free);
	}
	return (NULL);
}

t_player	*free_player(t_player *player)
{
	if (player)
	{
		if (player->coords)
			free(player->coords);
		free(player);
	}
	return (NULL);
}

t_animframe	*free_anim(mlx_t *mlx, t_animframe *anim)
{
	int	cpt;

	if (!anim)
		return (NULL);
	cpt = 0;
	while (cpt < anim->size)
	{
		if (anim->texts[cpt])
			mlx_delete_texture(anim->texts[cpt]);
		if (anim->imgs[cpt])
			mlx_delete_image(mlx, anim->imgs[cpt]);
		cpt++;
	}
	free(anim);
	return (NULL);
}

void	free_gconf_bis(t_graphconf *g_conf)
{
	if (g_conf->sel_map)
		free(g_conf->sel_map);
	free(g_conf->i_str);
	free(g_conf->m_str);
	system("killall afplay 2> /dev/null");
}

t_graphconf	*free_gconf(t_graphconf *g_conf)
{
	int	cpt;

	cpt = 0;
	while (cpt < 8)
	{
		if (g_conf->texts[cpt])
			mlx_delete_texture(g_conf->texts[cpt]);
		if (g_conf->imgs[cpt++])
			mlx_delete_image(g_conf->mlx, g_conf->imgs[cpt - 1]);
	}
	while (cpt < 10)
		if (g_conf->imgs[cpt++])
			mlx_delete_image(g_conf->mlx, g_conf->imgs[cpt - 1]);
	if (g_conf->anims)
	{
		while (cpt < 14)
			free_anim(g_conf->mlx, g_conf->anims[13 - cpt++]);
		free(g_conf->anims);
	}
	free_gconf_bis(g_conf);
	mlx_terminate(g_conf->mlx);
	free_conf(g_conf->conf);
	free(g_conf);
	return (NULL);
}
