/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:26:19 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/28 14:36:41 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graph_refresh_mcount(t_graphconf *g_conf)
{
	mlx_delete_image(g_conf->mlx, g_conf->imgs[11]);
	g_conf->m_str = ft_strjoin("Moves : ",
			ft_itoa(g_conf->conf->player->move_count++ + 1));
	g_conf->imgs[11] = mlx_put_string(g_conf->mlx, g_conf->m_str, 10, 0);
}

void	graph_refresh_icount(t_graphconf *g_conf)
{
	char	*p1;
	char	*p2;

	mlx_delete_image(g_conf->mlx, g_conf->imgs[12]);
	p1 = ft_strjoin("Items : ", ft_itoa(g_conf->conf->player->item_count));
	p2 = ft_strjoin(p1, "/");
	g_conf->i_str = ft_strjoin(p2, ft_itoa(g_conf->conf->collectibles_nbr));
	g_conf->imgs[12] = mlx_put_string(g_conf->mlx, g_conf->i_str,
			W_WIDTH * 2 - 150, 0);
}

void	graph_dispawn_item(t_coords *p_coords, mlx_image_t *img, char **map)
{
	size_t		cpt;
	size_t		cpt2;
	int			index;

	cpt = 1;
	index = 0;
	while (map[cpt])
	{
		cpt2 = 1;
		while (map[cpt][cpt2])
		{
			if (map[cpt][cpt2] == 'C' || map[cpt][cpt2] == 'c')
				index++;
			if (p_coords->y == cpt && p_coords->x == cpt2)
			{
				img->instances[index - 1].enabled = 0;
				return ;
			}
			cpt2++;
		}
		cpt++;
	}
}

void	graph_move_player(t_coords *p_coords, mlx_image_t *img, size_t x_size,
	size_t y_size)
{
	img->instances[0].x = (W_WIDTH - (x_size / 2) * 64)
		+ (p_coords->x) * 64 - 15;
	img->instances[0].y = W_HEIGHT - ((y_size / 2) * 64)
		+ ((p_coords->y - 1) * 64) - 32;
}

void	graph_move_ennemy(t_coords *e_coords, mlx_image_t *img, int index,
	t_graphconf *g_conf)
{
	img->instances[index].x = (W_WIDTH - (g_conf->conf->x_size / 2) * 64)
		+ (e_coords->x) * 64;
	img->instances[index].y = W_HEIGHT - ((g_conf->conf->y_size / 2) * 64)
		+ ((e_coords->y - 1) * 64) + 15;
}
