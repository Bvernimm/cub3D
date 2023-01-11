/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:32:27 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 14:17:20 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de gerer le deplacement en fonction du nombre pseudo-aleatoire
 * 
 * @param random nombre pseudo-aleatoire
 * @param pos nouvelle position de l'ennemie
 */
static void	handle_directional_move(int random, t_coord *pos)
{
	if (random == 0)
		pos->x--;
	else if (random == 1)
		pos->x++;
	else if (random == 2)
		pos->y--;
	else if (random == 3)
		pos->y++;
}

static void	move_enemy(t_game *game, t_sprite *enemy, t_coord coord)
{
	t_coord	old;

	if (check_move_enemy(game->map, coord.x, coord.y) == 1)
	{
		if (collision_player(coord, game->camera.position))
			bad_ending(game, 0);
		old.x = (int)floor(enemy->coord.x);
		old.y = (int)floor(enemy->coord.y);
		if (game->map[old.y][old.x] != '3')
			game->map[old.y][old.x] = '0';
		set_vector(&enemy->coord, coord.x + 0.5, coord.y + 0.5);
		if (game->map[coord.y][coord.x] != '3')
			game->map[coord.y][coord.x] = 'V';
	}
}

static void	pursuit(t_coord player, t_coord *coord)
{
	int	k;
	int	l;
	int	move;

	move = get_move_direction(player, coord, &k, &l);
	if (move)
	{
		k = 1;
		if (!l)
			k *= -1;
		coord->x = coord->x + k;
	}
	else
	{
		l = 1;
		if (!k)
			l *= -1;
		coord->y = coord->y + l;
	}
}

void	handle_enemy_move(t_game *game, t_sprite *enemy)
{
	int		random;
	t_coord	coord;
	t_coord	player;

	coord.x = (int)floor(enemy->coord.x);
	coord.y = (int)floor(enemy->coord.y);
	player.x = (int)floor(game->camera.position.x);
	player.y = (int)floor(game->camera.position.y);
	if (player_around(player, coord))
		pursuit(player, &coord);
	else
	{
		random = rand() % 5;
		if (random == 5)
			return ;
		handle_directional_move(random, &coord);
	}
	move_enemy(game, enemy, coord);
}
