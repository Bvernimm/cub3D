/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:32:56 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:32:57 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_sprite(t_sprite *old, t_sprite new)
{
	old->tex = new.tex;
	old->distance = new.distance;
	old->coord.x = new.coord.x;
	old->coord.y = new.coord.y;
	old->number = new.number;
	old->type = new.type;
	old->is_visible = new.is_visible;
}

static void	inverse_sprites(t_sprite *sprites, t_sprite *inverse, int count)
{
	int	i;
	int	j;

	i = -1;
	j = count;
	while (++i < count && --j >= 0)
	{
		copy_sprite(&sprites[i], inverse[j]);
	}
	free(inverse);
}

void	sort_sprites(t_game *game)
{
	t_sprite	*sprites;
	int			i;
	int			j;

	sprites = (t_sprite *)malloc(sizeof(t_sprite) * game->nb_sprites);
	if (!sprites)
		print_error(game, "Error\n");
	i = -1;
	while (++i < game->nb_sprites)
		sprites[i].number = -1;
	i = -1;
	while (++i < game->nb_sprites)
	{
		if (i == 0)
			j = get_min(game, sprites, i, 0.);
		else
			j = get_min(game, sprites, i, sprites[i - 1].distance);
		copy_sprite(&sprites[i], game->sprites[j]);
	}
	inverse_sprites(game->sprites, sprites, game->nb_sprites);
}

int	sprite_case(t_sprite *sprites, t_game *game, t_coord coord, int k)
{
	if (is_sprite_case(game->map[coord.y][coord.x]))
	{
		sprites[k].type = game->map[coord.y][coord.x];
		sprites[k].distance = 0;
		sprites[k].is_visible = 1;
		sprites[k].number = k;
		load_sprites_tex(game, &sprites[k]);
		set_vector(&sprites[k].coord, coord.x + 0.5, coord.y + 0.5);
		return (1);
	}
	return (0);
}
