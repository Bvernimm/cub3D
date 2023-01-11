/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:51:10 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:51:10 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de modifier la position de la caméra
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param cam  Variable stockant les differentes infos sur la caméra
 * @param id Identifiant de la direction
 */
void	move_pos(t_game *game, t_camera *cam, int id)
{
	int		i;
	double	value;
	double	pos;

	i = -1;
	if (id == 1)
		i = 1;
	value = i * game->camera.direction.x * game->speed.move;
	pos = cam->position.x + value;
	if (!check_pos(game->map, pos, cam->position.y, game))
		set_double_value(&cam->position.x, pos);
	value = i * game->camera.direction.y * game->speed.move;
	pos = cam->position.y + value;
	if (!check_pos(game->map, cam->position.x, pos, game))
		set_double_value(&cam->position.y, pos);
}

void	decal_pos(t_game *game, t_camera *cam, int id)
{
	int		i;
	double	value;
	double	pos;

	i = id;
	value = i * game->camera.direction.y * game->speed.move;
	pos = cam->position.x + value;
	if (!check_pos(game->map, pos, cam->position.y, game))
		set_double_value(&cam->position.x, pos);
	i = -i;
	value = i * game->camera.direction.x * game->speed.move;
	pos = cam->position.y + value;
	if (!check_pos(game->map, cam->position.x, pos, game))
		set_double_value(&cam->position.y, pos);
}

/**
 * @brief Permet de faire tourner la caméra dans la direction voulue
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param id Identifiant de la direction
 */
void	rotate_cam(t_game *game, int id)
{
	int	i;

	i = 1;
	if (id % 2)
		i = -1;
	cos_sin(&game->camera.direction, game->speed.rotation * i);
	cos_sin(&game->camera.plane, game->speed.rotation * i);
}
