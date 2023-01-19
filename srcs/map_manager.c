/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:41:22 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/28 17:41:48 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ennemy_count(char **map)
{
	int	cpt;
	int	cpt2;
	int	count;

	count = 0;
	cpt = 1;
	while (map[cpt])
	{
		cpt2 = 1;
		while (map[cpt][cpt2])
			if (map[cpt][cpt2++] == 'S')
				count++;
		cpt++;
	}
	return (count);
}

size_t	line_is_valid(char *line, t_mapconf *conf, size_t cpt)
{
	if (conf->x_size == 0)
		conf->x_size = ft_strlen(line);
	if (ft_strlen(line) != conf->x_size || conf->x_size > 30)
		return (0);
	if (ft_strchr(line, 'P') != -1)
	{
		if (conf->player == NULL)
			conf->player = new_player(new_coords(ft_strchr(line, 'P'), cpt));
		else
			return (0);
	}
	if (ft_strchr(line, 'E') != -1)
	{
		if (conf->escap)
			return (0);
		else
			conf->escap = new_coords(ft_strchr(line, 'E'), cpt);
	}
	if (ft_strchr(line, 'C') != -1)
		conf->collectibles_nbr += ft_nbr_of(line, 'C');
	return (!wrong_tile(line));
}

int	encapsuled(t_mapconf *conf)
{
	size_t	cpt;

	cpt = 0;
	while (conf->map[0][cpt])
		if (conf->map[0][cpt++] != '1')
			return (0);
	cpt = -1;
	while (++cpt < conf->y_size && conf->map[cpt])
		if (conf->map[cpt][conf->x_size - 1] != '1' || conf->map[cpt][0] != '1')
			return (0);
	cpt = 0;
	while (conf->map[conf->y_size - 1][cpt])
		if (conf->map[conf->y_size - 1][cpt++] != '1')
			return (0);
	return (1);
}

int	fill_map(t_mapconf **conf, char *filename)
{
	int		cpt;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	cpt = 0;
	while (line)
	{
		if (line_is_valid(line, (*conf), cpt))
			(*conf)->map[cpt++] = line;
		else
		{
			(*conf)->map[cpt] = NULL;
			return (0);
		}
		line = get_next_line(fd);
	}
	close(fd);
	(*conf)->map[(*conf)->y_size] = NULL;
	return (!((((*conf)->escap) == NULL) || (((*conf)->player) == NULL)
			|| (((*conf)->collectibles_nbr) < 1)));
}

t_mapconf	*init_map(char *filename)
{
	int			fd;
	t_mapconf	*conf;

	fd = open(filename, O_RDONLY);
	conf = init_map_struct();
	while (get_next_line(fd))
		conf->y_size++;
	close(fd);
	if (conf->y_size < 3 || conf->y_size > 15)
		return (free_conf(conf));
	conf->map = (char **)malloc(sizeof(char *) * (conf->y_size + 1));
	if (!conf->map)
		return (free_conf(conf));
	if (!fill_map(&conf, filename) || !encapsuled(conf)
		|| !find_way_init(conf))
		return (free_conf(conf));
	init_enemies(conf);
	return (conf);
}
