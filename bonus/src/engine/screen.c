/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:49:57 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:44:00 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycast(t_game *game)
{
	int	i;
	int	h;

	i = -1;
	while (++i < game->win.width)
	{
		update_raycast(game, &game->ray, &game->camera, i);
		if (game->ray.perp_wall_dist > 0)
		{
			h = fabs(game->win.height / game->ray.perp_wall_dist);
			if (h < 1)
				h = 1;
			set_int_value(&game->ray.column, i);
			set_int_value(&game->ray.height, h);
			draw_wall(game, &game->ray);
			if (game->ray.height < game->win.height)
				draw_textured_sky_floor(game, &game->ray);
			if (game->nb_sprites > 0)
				game->perp_wall[i] = game->ray.perp_wall_dist;
		}
	}
}

static int	get_color_font(int level)
{
	if (level == 0)
		return (TUTO_FONT);
	else if (level == 1)
		return (CAVE_FONT);
	return (0x0);
}

/**
 * @brief Met à jour ce qu'il y a à l'écran
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param i Variable déclarée précédemment
 * @param h Variable déclarée précédemment
 */
void	update_screen(t_game *game)
{
	move(game);
	draw_font(game, get_color_font(game->control.level));
	raycast(game);
	if (game->nb_sprites > 0)
	{
		load_sprites(game);
		draw_sprites(game);
	}
	draw_minimap(game);
	if (game->control.is_reading == 1)
		draw_document(game);
	else
		if (game->control.cutscene == 0)
			draw(game);
}
