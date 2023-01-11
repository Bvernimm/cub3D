/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:32:33 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:32:33 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_tex(t_game *game, t_sprite *enemy, int frames)
{
	load_enemy_tex(game, enemy, frames);
}

int	handle_enemy(t_game *game, t_sprite *enemy, int frames)
{
	change_tex(game, enemy, frames);
	handle_enemy_move(game, enemy);
	return (1);
}
