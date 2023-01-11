/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:35:22 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 14:07:08 by bvernimm         ###   ########.fr       */
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
	if (key == KEY_M)
	{
		if (game->control.use_mouse)
			game->control.use_mouse = 0;
		else
			game->control.use_mouse = 1;
	}
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
		game->control.sprint = 1;
	if (game->control.is_reading == 1)
		game->control.is_reading = 0;
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
