/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:12 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/27 22:20:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "struct.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# define IMG_PATH "imgs/"
# define SL_PATH "imgs/slime"
# define MAP_PATH "maps/"
# define MERROR "MAP ERROR"
# define ESC "Rage quited!\n"
# define WIN "%sWIN%s %s exit reached with all collectibles in %d moves !%c"
# define DEATH "%sDEAD%s %s with %d/%d collectibles in %d moves%c"
# define TEXT_ERROR "error during textures loading\n"
# define CROSS "cross pressed\n"
# define MESC "M pressed return to menu\n"
# define FRAME_RATE 10
# define DEATH_FRATE 7
# define WIN_FRATE 6
# define NBR_IMGS 13
# define NBR_TEXTS 11
# define W_HEIGHT 540
# define W_WIDTH 960

// gestion map
int			fill_map(t_mapconf **conf, char *filename);
size_t		line_is_valid(char *line, t_mapconf *conf, size_t cpt);
int			encapsuled(t_mapconf *conf);
t_mapconf	*init_map(char *filename);

// pathfinder
int			find_way_init(t_mapconf *conf);
int			find_way(char **map, t_coords *act, t_list **closed, int *args);

// moves
int			key_manager(t_graphconf *g_conf, mlx_key_data_t keydata);
int			move_right(t_graphconf *g_conf);
int			move_up(t_graphconf *g_conf);
int			move_down(t_graphconf *g_conf);
int			move_left(t_graphconf *g_conf);
int			apply_move(t_graphconf *g_conf);

// utils
int			is_end(char **map, t_player *player, size_t ttcol);
int			nbr_move_pos(char **map, t_coords *act);
int			is_in(t_list *closed, t_coords *act, int x, int y);
int			same_coords(t_coords *c1, t_coords *act, int x, int y);
int			wrong_tile(char *line);
void		check_file_name(char *str);
void		texts_null(t_graphconf *g_conf, int start, int end);
void		imgs_null(t_graphconf *g_conf, int start, int end);
void		delete_imgs(t_graphconf *g_conf, int start, int end);
void		update_ppos_menu(t_graphconf *g_conf, t_coords *act);
void		update_ppos_game(t_graphconf *g_conf, t_coords *act);
void		frame_update_bis(t_graphconf *g_conf);
t_player	*init_menuplayer(t_graphconf *g_conf);

// 2D graph
int			fill_win(t_graphconf *g_conf, mlx_t *mlx, size_t cpt);
int			win_init(char *filename);
void		graph_dispawn_item(t_coords *p_coords, mlx_image_t *img,
				char **map);
void		graph_move_player(t_coords *p_coords, mlx_image_t *img,
				size_t x_size, size_t y_size);
void		graph_refresh_mcount(t_graphconf *g_conf);
void		graph_refresh_icount(t_graphconf *g_conf);
void		graph_move_ennemy(t_coords *e_coords, mlx_image_t *img, int index,
				t_graphconf *g_conf);
void		init_graph_player(t_graphconf *g_conf);
void		init_graph_enemies(t_graphconf *g_conf);
void		init_graph_ennemies_bis(t_graphconf *g_conf, size_t *cpt);
void		init_gameimg(mlx_t *mlx, t_graphconf *g_conf);
void		init_gameanim(mlx_t *mlx, t_graphconf *g_conf);
void		init_img(mlx_t *mlx, t_graphconf *g_conf);
void		update_player_framez(t_graphconf *g_conf, int ref, int rd);

// free fct
t_player	*free_player(t_player *player);
t_mapconf	*free_conf(t_mapconf *conf);
t_graphconf	*free_gconf(t_graphconf *g_conf);
t_animframe	*free_anim(mlx_t *mlx, t_animframe *anim);

// struct init
t_mapconf	*init_map_struct(void);
t_list		*new_list(t_coords *act);
t_coords	*new_coords(int x, int y);
t_player	*new_player(t_coords *coords);
int			*new_args(int col_max);
t_graphconf	*new_graphconf(t_mapconf *conf, mlx_image_t **imgs,
				mlx_texture_t **texts, mlx_t *mlx);
void		init_enemies(t_mapconf *conf);
t_animframe	*new_animation(char *base_filename, int size, mlx_t *mlx);

// ennemies manager
void		apply_ennemies_moves(t_list *ennemy, t_coords *new_coords,
				t_graphconf *g_conf, int cpt);
void		gen_ennemies_moves(t_graphconf *g_conf);
int			ennemy_on_player(t_graphconf *g_conf);
void		random_move(int x, t_list *ennemies, t_graphconf *g_conf, int cpt);
void		default_move(t_graphconf *g_conf, t_list *ennemy, int cpt);

// animation
void		animation_manager(void *param);
void		update_all_frame(int cpt, int old_index, t_graphconf *g_conf);
void		update_ennemies(int old_index, t_graphconf *g_conf);
void		update_player(int cpt, int old_index, t_graphconf *g_conf);
void		black_fade(t_graphconf *g_conf);
void		do_win_anim(t_animframe *anim, mlx_t *mlx, t_graphconf *g_conf,
				int *cpt);
void		do_death_anim(t_animframe *anim, mlx_t *mlx, t_graphconf *g_conf,
				int *cpt);
void		white_fade(t_graphconf *g_conf);
void		update_menuplayer(int cpt, int old_index, t_graphconf *g_conf);

// errors
void		check_text_error(t_graphconf *g_conf, int nb);
void		frame_error(t_graphconf *g_conf);

// menu moves
int			apply_menumove(t_graphconf *g_conf);
int			menumove_left(t_graphconf *g_conf);
int			menumove_right(t_graphconf *g_conf);
int			menumove_up(t_graphconf *g_conf);
int			menumove_down(t_graphconf *g_conf);

// menu
int			menukey_manager(t_graphconf *g_conf, mlx_key_data_t keydata);
void		win_menu(t_graphconf *g_conf);
void		init_menuwin(t_graphconf *g_conf);

// game window
int			win_game(t_graphconf *g_conf);
void		refresh_win(t_graphconf *g_conf);

void		end_game(t_graphconf *g_conf, int opt);
void		end_game_bis(t_graphconf *g_conf, int opt);
void		end_game_manager(t_graphconf *g_conf);

#endif