/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:53:38 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 08:19:48 by llaruell         ###   ########.fr       */
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

static void	play_game(t_game *game)
{
	static int	change;
	static int	frames = 0;
	static int	id_frames = 0;

	if (!change || change >= 1)
		update_screen(game);
	update_speed(game);
	change = check_move(game);
	if (game->nb_enemies && (frames % SPEED_ANIM) == 0)
	{
		game->index_enemy = get_index_enemy(game->sprites,
				game->nb_sprites, game);
		change += handle_enemy(game,
				&game->sprites[game->index_enemy], id_frames);
		id_frames++;
		if (id_frames == 4)
			id_frames = 0;
	}
	frames++;
	if (frames >= 60)
		frames = 0;
}

void	handle_game(t_game *game)
{
	if (game->control.cutscene)
	{
		cutscene(game, game->frames);
		game->frames++;
		if (game->frames >= 240)
		{
			game->frames = 0;
			game->control.cutscene = 0;
			change_song(game, 1);
		}
	}
	else if (game->control.menu)
		menu(game);
	else if (game->control.endgame == 0)
		play_game(game);
}

/**
 * @brief Loop du jeu
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 */
int	loop(t_game *game)
{
	if (game->control.endgame == 0)
		handle_game(game);
	else
	{
		bad_ending(game, game->frames);
		game->frames++;
	}
	return (0);
}
