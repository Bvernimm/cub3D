/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:20 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:49:20 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	{
		game->speed.q_move = Q_MOVE;
		game->speed.q_rota = Q_ROTA;
	}
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
	return (key);
}
