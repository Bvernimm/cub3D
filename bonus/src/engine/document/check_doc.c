/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:29:42 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 08:35:09 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_tuto(t_game *game, int x, int y)
{
	if (x == 16 && y == 7)
		game->control.id_doc = 1;
	else if (x == 21 && y == 8)
		game->control.id_doc = 2;
}

static void	check_game(t_game *game, int x, int y)
{
	if (x == 45 && y == 42)
		game->control.id_doc = 1;
	else if (x == 51 && y == 38)
		game->control.id_doc = 2;
	else if (x == 1 && y == 35)
		game->control.id_doc = 3;
	else if (x == 26 && y == 11)
		game->control.id_doc = 4;
	else if (x == 61 && y == 1)
		game->control.id_doc = 5;
	else if (x == 66 && y == 1)
		game->control.id_doc = 6;
	else if (x == 26 && y == 18)
		game->control.id_doc = 7;
	else if (x == 1 && y == 25)
		game->control.id_doc = 8;
	else if (x == 15 && y == 40)
		game->control.id_doc = 9;
	else if (x == 94 && y == 39)
		game->control.id_doc = 10;
}

void	check_doc(t_game *game, int x, int y)
{
	if (game->control.level == 0)
		check_tuto(game, x, y);
	else if (game->control.level == 1)
		check_game(game, x, y);
	game->control.is_reading = 1;
}
