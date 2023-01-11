/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:48:33 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 07:48:33 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de déplacer ou faire tourner la caméra
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 */
void	move(t_game *game)
{	
	if (game->move.forward == 1)
		move_pos(game, &game->camera, 0);
	else if (game->move.backward == 1)
		move_pos(game, &game->camera, 1);
	if (game->move.walk_right == 1)
		decal_pos(game, &game->camera, -1);
	else if (game->move.walk_left == 1)
		decal_pos(game, &game->camera, 1);
	if (game->move.left == 1)
		rotate_cam(game, 1);
	else if (game->move.right == 1)
		rotate_cam(game, 2);
}
