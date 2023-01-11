/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:49:08 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 13:50:37 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check si un mouvement a été effectué
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @return Si oui 1, sinon 0
 */
static int	check_move(t_game *game)
{
	if (game->move.forward == 1 || game->move.backward == 1
		|| game->move.left == 1 || game->move.right == 1
		|| game->move.walk_right == 1 || game->move.walk_left == 1)
		return (1);
	return (0);
}

/**
 * @brief Loop du jeu
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 */
int	loop(t_game *game)
{
	int			i;
	int			h;
	static int	change;

	i = 0;
	h = 0;
	if (!change || change == 1)
		update_screen(game, i, h);
	update_speed(game);
	change = check_move(game);
	return (0);
}
