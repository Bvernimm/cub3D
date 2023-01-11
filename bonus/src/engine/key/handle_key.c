/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:35:16 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:47:55 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check si la touche est une touche de direction
 * 
 * @param key La touche
 * @return 1 si il s'agit d'unt touche de direction, 0 sinon
 */
int	is_moving_key(int key)
{
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D
		|| key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
		|| key == KEY_RIGHT || key == KEY_SHIFT)
		return (1);
	return (0);
}

/**
 * @brief Check si la touche est une touche spéciale
 * 
 * @param key La touche
 * @return 1 si il s'agit d'unt touche spéciale, 0 sinon
 */
int	is_special_key(int key)
{
	if (key == KEY_ESC || key == KEY_SPACE || key == KEY_M
		|| key == KEY_P)
		return (1);
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	if (game->control.use_mouse == 1)
	{
		(void) y;
		if (x > game->win.width / 2)
		{
			game->move.right = 1;
			game->control.mouse = 1;
		}
		else if (x < game->win.width / 2)
		{
			game->move.left = 1;
			game->control.mouse = 1;
		}
		game->speed.q_rota = Q_ROTA_MOUSE;
		mouse_move(game->win.width / 2 + 100, game->win.height / 2 + 100);
	}
	return (0);
}
