/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:42 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:49:42 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(char *file, t_game *game, int i)
{
	while (line_is_empty(file, i) == 0)
		i++;
	game->map = get_map(file + i);
	if (!game->map)
		ft_error("map problem\n", game);
	if (check_char(game->map) != 0)
		ft_error("wrong character in map\n", game);
	if (check_walls_1(game->map) != 0)
		ft_error("map is not surrounded by walls\n", game);
	if (check_walls_2(game->map) != 0)
		ft_error("map is not surrounded by walls\n", game);
	if (hole_in_map(game->map) != 0)
		ft_error("emplty line in map\n", game);
	if (find_player(game->map, game) != 1)
		ft_error("player spawn error\n", game);
	return (0);
}

int	hole_in_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] && line_is_empty(map[i], 0) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	line_is_empty(char *file, int i)
{
	while (file[i] && file[i] != '\n')
	{
		if (file[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\n' && map[i][j] != '0'
				&& map[i][j] != '1' && map[i][j] != 'N' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != 'S')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	find_player(char **map, t_game *game)
{
	int	player_found;
	int	i;
	int	j;

	player_found = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S')
			{
				game->start_orientation = map[i][j];
				game->camera.position.x = j + 0.5;
				game->camera.position.y = i + 0.5;
				player_found++;
			}
			j++;
		}
		i++;
	}
	return (player_found);
}
