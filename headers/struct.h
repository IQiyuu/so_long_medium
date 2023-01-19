/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:42:17 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 18:20:32 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

typedef struct s_player
{
	t_coords	*coords;
	size_t		item_count;
	size_t		move_count;
}	t_player;

typedef struct s_mapconf
{
	size_t		x_size;
	size_t		y_size;
	t_player	*player;
	t_list		*ennemies;
	size_t		collectibles_nbr;
	char		**map;
	t_coords	*escap;
}	t_mapconf;

typedef struct s_animframe
{
	mlx_texture_t	**texts;
	mlx_image_t		**imgs;
	int				index;
	int				enable;
	int				count;
	int				size;
}	t_animframe;

typedef struct s_menu
{
	size_t	unlocked_lvls;
}	t_menu;

typedef struct s_graphconf
{
	t_mapconf		*conf;
	mlx_t			*mlx;
	mlx_image_t		**imgs;
	mlx_texture_t	**texts;
	char			*i_str;
	char			*m_str;
	t_animframe		**anims;
	int				anim_nbr;
	t_menu			*menu;
	char			*sel_map;
	int				in_game;
	char			*perso;
	int				perso_f;
}	t_graphconf;

#endif