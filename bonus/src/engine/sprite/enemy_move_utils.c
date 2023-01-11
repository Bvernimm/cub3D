/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:32:23 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:32:23 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_move_enemy(char **map, int x, int y)
{
	int	columns;
	int	rows;

	if (x < 0 && y < 0)
		return (0);
	rows = get_array(map);
	if (y >= rows)
		return (0);
	columns = ft_strlen(map[0]);
	if (x >= columns)
		return (0);
	if (x <= 57 || x >= 96 || y <= 17 || y >= 35)
		return (0);
	if (map[y][x] == '1' || map[y][x] == '2'
		|| is_sprite_case(map[y][x]))
		return (0);
	return (1);
}

int	collision_player(t_coord enemy, t_vector player)
{
	t_coord	coll;

	coll.x = (int)floor(player.x);
	coll.y = (int)floor(player.y);
	if (coll.x == enemy.x && coll.y == enemy.y)
		return (1);
	return (0);
}

int	player_around(t_coord player, t_coord coord)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = -1;
	if (player.x > coord.x)
		k = 1;
	l = -1;
	if (player.y > coord.y)
		l = 1;
	i = -1;
	while (++i < ENEMY_DETECTION)
	{
		j = -1;
		while (++j < ENEMY_DETECTION)
		{
			if (player.x == coord.x + (j * k)
				&& player.y == coord.y + (i * l))
				return (1);
		}
	}
	return (0);
}

int	get_interval(int x, int y, int id)
{
	int	i;

	i = 0;
	if (x != y)
	{
		if (id)
		{
			while (x > y + i)
				i++;
		}
		else
		{
			while (x < y - i)
				i++;
		}
	}
	return (i);
}

int	get_move_direction(t_coord player, t_coord *coord, int *k, int *l)
{
	int	i;
	int	j;

	*l = 0;
	*k = 0;
	if (player.x > coord->x)
	{
		*l = 1;
		i = get_interval(player.x, coord->x, 1);
	}
	else
		i = get_interval(player.x, coord->x, 0);
	if (player.y > coord->y)
	{
		*k = 1;
		j = get_interval(player.y, coord->y, 1);
	}
	else
		j = get_interval(player.y, coord->y, 0);
	if (i > j)
		return (1);
	else
		return (0);
}
