/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_sky.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:46:25 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:47:25 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_floor_wall(t_raycast *ray, t_vector *floor_wall)
{
	if (ray->side == 0 && ray->direction.x > 0)
	{
		floor_wall->x = ray->map.x;
		floor_wall->y = ray->map.y + ray->wall_x;
	}
	else if (ray->side == 0 && ray->direction.x < 0)
	{
		floor_wall->x = ray->map.x + 1.0;
		floor_wall->y = ray->map.y + ray->wall_x;
	}
	else if (ray->side == 1 && ray->direction.y > 0)
	{
		floor_wall->x = ray->map.x + ray->wall_x;
		floor_wall->y = ray->map.y;
	}
	else if (ray->side == 1 && ray->direction.y < 0)
	{
		floor_wall->x = ray->map.x + ray->wall_x;
		floor_wall->y = ray->map.y + 1.0;
	}
}

static void	draw_sky(t_game *game, t_vector current_floor,
	double current_dist, int y)
{
	int	color;

	game->t_sky.x = (int)(current_floor.x * game->t_sky.width)
		% game->t_sky.width;
	game->t_sky.y = (int)(current_floor.y * game->t_sky.height)
		% game->t_sky.height;
	color = shader(current_dist / 1.5, get_color_tex(&game->t_sky),
			game->control.shade);
	pixel_draw(game->ray.column, game->win.height - y - 1, color, game);
}

static void	draw_floor(t_game *game, t_vector current_floor,
	double current_dist, int y)
{
	int	color;

	game->t_floor.x = (int)(current_floor.x * game->t_floor.width)
		% game->t_floor.width;
	game->t_floor.y = (int)(current_floor.y * game->t_floor.height)
		% game->t_floor.height;
	color = shader(current_dist / 1.5, get_color_tex(&game->t_floor),
			game->control.shade);
	pixel_draw(game->ray.column, y, color, game);
}

/**
 * @brief Permet d'afficher des textures sur le sol et le plafond
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param ray Variable stockant les differentes infos sur le raycasting
 */
void	draw_textured_sky_floor(t_game *game, t_raycast *ray)
{
	t_vector	floor_wall;
	t_vector	current_floor;
	double		current_dist;
	int			y;
	double		weight;

	init_floor_wall(ray, &floor_wall);
	y = game->win.height / 2 + (ray->height / 2) - 1;
	while (++y < game->win.height)
	{
		current_dist = game->win.height / (2.0 * (double)y - game->win.height);
		weight = current_dist / ray->perp_wall_dist;
		current_floor.x = weight * floor_wall.x + (1.0 - weight)
			* game->camera.position.x;
		current_floor.y = weight * floor_wall.y + (1.0 - weight)
			* game->camera.position.y;
		draw_floor(game, current_floor, current_dist, y);
		draw_sky(game, current_floor, current_dist, y);
	}
}
