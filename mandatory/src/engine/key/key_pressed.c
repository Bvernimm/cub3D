/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:17 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:49:17 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Effectuer des commandes spécifiques
 * 
 * @param key Touche pressée
 * @param game Structure contenant nos données générales
 */
static void	commands(t_game *game, int key)
{
	if (key == KEY_ESC)
		exit_game(game);
	if (key == KEY_SPACE)
		printf("Unlock the 29.99$ dlc to jump !\n");
}

/**
 * @brief Gère les touches directionnelles
 * 
 * @param game Structure contenant nos données générales
 * @param key Touche pressée
 */
static void	get_move(t_game *game, int key)
{
	if (key == KEY_UP || key == KEY_W)
		game->move.backward = 1;
	else if (key == KEY_DOWN || key == KEY_S)
		game->move.forward = 1;
	if (key == KEY_LEFT)
		game->move.left = 1;
	else if (key == KEY_RIGHT)
		game->move.right = 1;
	if (key == KEY_A)
		game->move.walk_left = 1;
	else if (key == KEY_D)
		game->move.walk_right = 1;
	if (key == KEY_SHIFT)
	{
		game->speed.q_move = Q_MOVE_SPRINT;
		game->speed.q_rota = Q_ROTA_SPRINT;
	}
}

/**
 * @brief Gère la gestion des touches pressées
 * 
 * @param key Touche pressée
 * @param game Structure contenant nos données générales
 * @return Touche pressée
 */
int	key_pressed(int key, t_game *game)
{
	if (is_moving_key(key))
		get_move(game, key);
	else if (is_special_key(key))
		commands(game, key);
	return (key);
}
