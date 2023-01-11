/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:48:44 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 13:42:49 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Met à jour ce qu'il y a à l'écran
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param i Variable déclarée précédemment
 * @param h Variable déclarée précédemment
 */
void	update_screen(t_game *game, int i, int h)
{
	move(game);
	draw_font(game);
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
				draw_floor_sky(game, &game->ray);
		}
	}
	draw(game);
}
