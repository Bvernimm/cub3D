/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:54:21 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 12:52:12 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_sprite_case(char c)
{
	if (c == '4' || c == '5' || c == '6' || c == '7'
		|| c == '8' || c == '9' || c == 'C' || c == 'c'
		|| c == 'B' || c == 'b' || c == 'V' || c == 'K')
		return (1);
	return (0);
}

static int	count_sprites(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_sprite_case(map[i][j]) == 1)
				++count;
		}
	}
	return (count);
}

static int	count_enemy(char **map, t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'V')
				++count;
		}
	}
	if (count > 1)
		ft_error("Too many ennemies\n", game);
	return (count);
}

int	get_index_enemy(t_sprite *sprites, int count, t_game *game)
{
	int	i;

	if (game->nb_enemies == 0)
		return (-1);
	i = -1;
	while (++i < count)
	{
		if (sprites[i].type == 'V')
			return (i);
	}
	return (-1);
}

void	check_sprites(t_game *game)
{
	game->sprites = NULL;
	game->nb_sprites = count_sprites(game->map);
	if (game->nb_sprites > 0)
	{
		game->nb_enemies = count_enemy(game->map, game);
		game->perp_wall = (double *)malloc(sizeof(*game->perp_wall)
				* game->win.width);
		if (!game->perp_wall)
			print_error(game, "Malloc Issues\n");
	}
}
