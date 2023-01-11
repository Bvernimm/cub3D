/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:32:52 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:32:52 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ligne_empty(t_tex *tex, int j)
{
	int	i;

	i = -1;
	tex->y = j;
	while (++i < tex->width)
	{
		tex->x = i;
		if (get_color_tex(tex) != 0x0)
			return (0);
	}
	return (1);
}

static int	col_empty(t_tex *tex, int j)
{
	int	i;

	i = -1;
	tex->x = j;
	while (++i < tex->height)
	{
		tex->y = i;
		if (get_color_tex(tex) != 0x0)
			return (0);
	}
	return (1);
}

static void	get_start_end(t_game *game, int i)
{
	int	j;

	j = 0;
	while (j < game->sprites[i].tex.height
		&& col_empty(&game->sprites[i].tex, j))
		j++;
	game->sprites[i].tex.start.x = j;
	while (j < game->sprites[i].tex.height
		&& !col_empty(&game->sprites[i].tex, j))
		j++;
	game->sprites[i].tex.end.x = j;
	j = 0;
	while (j < game->sprites[i].tex.height
		&& ligne_empty(&game->sprites[i].tex, j))
		j++;
	game->sprites[i].tex.start.y = j;
	while (j < game->sprites[i].tex.height
		&& !ligne_empty(&game->sprites[i].tex, j))
		j++;
	game->sprites[i].tex.end.y = j;
}

static t_sprite	*get_sprites(t_game *game, char **map)
{
	t_coord		index;
	int			k;
	t_sprite	*sprites;

	sprites = (t_sprite *)malloc(sizeof(t_sprite) * game->nb_sprites);
	if (!sprites)
		print_error(game, "Error\n");
	index.y = -1;
	k = 0;
	while (map[++index.y])
	{
		index.x = -1;
		while (map[index.y][++index.x])
		{
			if (sprite_case(sprites, game, index, k))
				k++;
		}
	}
	return (sprites);
}

void	load_sprites(t_game *game)
{
	int	i;

	if (game->sprites == NULL)
	{
		game->sprites = get_sprites(game, game->map);
		i = -1;
		while (++i < game->nb_sprites)
			get_start_end(game, i);
	}
}
