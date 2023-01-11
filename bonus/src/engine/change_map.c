/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:45:21 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/02 15:09:53 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_map(t_game *game)
{
	int	fd;

	free_matrice(game->map);
	fd = open(CAVE_MAP, O_RDONLY);
	if (fd < 0)
		ft_error("Could not open the map\n", game);
	check_file(fd, game);
	close (fd);
}

int	change_map(t_game *game, int id)
{
	stop();
	replace_map(game);
	load_textures(game, 1);
	init_camera(&game->camera, game->camera.position, game->start_orientation);
	free(game->sprites);
	check_sprites(game);
	game->control.level = id;
	game->control.shade = 1;
	game->control.cutscene = 1;
	return (1);
}
