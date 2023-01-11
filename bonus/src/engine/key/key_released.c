/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:40 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:39:41 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	commands(int key, t_game *game)
{
	if (key == KEY_P)
	{
		if (game->control.menu)
		{
			game->control.menu = 0;
			if (game->control.start)
			{
				on_off_song(game);
				game->control.start = 0;
			}
			else
				resume_song(game);
		}
		else
		{
			game->control.menu = 1;
			pause_song(game);
		}
	}
	if (key == KEY_SPACE)
		check_event(game);
}

/**
 * @brief Gère le relâchement des touches directionnelles
 * 
 * @param game Structure contenant nos données générales
 * @param key Touche relâchée
 */
static void	stop_move(t_game *game, int key)
{
	if (key == KEY_UP || key == KEY_W)
		game->move.backward = 0;
	else if (key == KEY_DOWN || key == KEY_S)
		game->move.forward = 0;
	if (key == KEY_LEFT)
		game->move.left = 0;
	else if (key == KEY_RIGHT)
		game->move.right = 0;
	if (key == KEY_A)
		game->move.walk_left = 0;
	else if (key == KEY_D)
		game->move.walk_right = 0;
	if (key == KEY_SHIFT)
		game->control.sprint = 0;
}

/**
 * @brief Gère le relâchement des touches
 * 
 * @param key Touche relâchée
 * @param game Structure contenant nos données générales
 * @return Touche relâchée
 */
int	key_released(int key, t_game *game)
{
	if (is_moving_key(key))
		stop_move(game, key);
	else
		commands(key, game);
	return (key);
}
