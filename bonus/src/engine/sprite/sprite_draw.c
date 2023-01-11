/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:32:48 by llaruell          #+#    #+#             */
/*   Updated: 2022/12/30 14:33:24 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_coord(t_coord *start, t_coord *end)
{
	if (start->x < 0)
		start->x = 0;
	if (start->y < 0)
		start->y = 0;
	if (end->x < 0)
		end->x = 0;
	if (end->y < 0)
		end->y = 0;
}

static	void	init_draw_sprites(t_calcul_sp *calcul, t_camera *cam,
	t_windows *win, t_vector coord)
{
	double	inv_det;

	inv_det = 1. / (cam->plane.x * cam->direction.y
			- cam->direction.x * cam->plane.y);
	calcul->pos.x = coord.x - cam->position.x;
	calcul->pos.y = coord.y - cam->position.y;
	calcul->transform.x = inv_det * ((cam->direction.y * calcul->pos.x)
			- (cam->direction.x * calcul->pos.y));
	calcul->transform.y = inv_det * ((-cam->plane.y * calcul->pos.x)
			+ (cam->plane.x * calcul->pos.y));
	set_int_value(&calcul->screen_x, (int)((win->width / 2)
			* (1 + calcul->transform.x / calcul->transform.y)));
	set_int_value(&calcul->height,
		abs((int)(win->height / calcul->transform.y)));
	set_int_value(&calcul->width,
		abs((int)(win->height / calcul->transform.y)));
	calcul->start.y = (-calcul->height / 2) + (win->height / 2);
	if (calcul->start.y < 0)
		calcul->start.y = 0;
	calcul->end.y = (calcul->height / 2) + (win->height / 2.);
	calcul->start.x = -calcul->width / 2 + calcul->screen_x;
	if (calcul->start.x < 0)
		calcul->start.x = 0;
	calcul->end.x = calcul->width / 2 + calcul->screen_x;
	check_coord(&calcul->start, &calcul->end);
}

static void	get_draw_y(t_game *game, t_calcul_sp *calcul,
	t_sprite *sprite, int i)
{
	int	j;
	int	d;
	int	color;

	j = calcul->start.y;
	while (j < game->win.height && j < calcul->end.y)
	{
		d = (j * 256) - (game->win.height * 128) + (calcul->height * 128);
		sprite->tex.y = ((d * sprite->tex.height) / calcul->height) / 256;
		if (check_limite(sprite->tex.y, sprite->tex.start, sprite->tex.end, 0))
		{
			color = shader(sprite->distance / 3, get_color_tex(&sprite->tex),
					game->control.shade);
			if (color != 0x0)
				pixel_draw(i, j, color, game);
		}
		j++;
	}
}

static	void	get_draw_x(t_game *game, t_calcul_sp *calcul, t_sprite *sprite)
{
	int	i;

	i = calcul->start.x;
	while (i < game->win.width && i < calcul->end.x)
	{
		sprite->tex.x = (int)(256 * (i
					- (-calcul->width / 2. + calcul->screen_x))
				* sprite->tex.width / calcul->width) / 256;
		if (check_limite(sprite->tex.x, sprite->tex.start, sprite->tex.end, 1)
			&& calcul->transform.y > 0
			&& calcul->transform.y < game->perp_wall[i])
			get_draw_y(game, calcul, sprite, i);
		i++;
	}
}

void	draw_sprites(t_game *game)
{
	t_calcul_sp	calcul;
	int			i;

	sprites_distances(game->camera.position, game->sprites, game->nb_sprites);
	sort_sprites(game);
	i = -1;
	while (++i < game->nb_sprites)
	{
		if (game->sprites[i].is_visible == 1)
		{
			init_draw_sprites(&calcul, &game->camera,
				&game->win, game->sprites[i].coord);
			get_draw_x(game, &calcul, &game->sprites[i]);
		}
	}
}
