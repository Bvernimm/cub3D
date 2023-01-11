/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutscene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:00:54 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 10:46:28 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_star(double *a, double *b, double *c, int size)
{
	*a = tan(M_PI * 0.4);
	*b = tan(M_PI * 0.2);
	*c = ceil(size * *a);
}

void	get_star(t_game *game, int x, int y, int size)
{
	double	a;
	double	b;
	double	c;
	double	d;

	init_star(&a, &b, &c, size);
	while (c >= 0)
	{
		d = ceil(0.55 * size * a / b - size);
		while (d >= -ceil(0.55 * size * a / b - size))
		{
			if ((c <= 0.55 * size * a && c >= (d + size) * b
					&& c >= (size - d) * b) || (c >= (d + size) * b
					&& c <= (d + size) * a && c <= (size - d) * a)
				|| (c <= (size - d) * a && c >= (size - d) * b
					&& c <= (d + size) * a))
				pixel_draw((int)(x + d), (int)(y + c), C_STAR, game);
			d--;
		}
		c--;
	}
}

static void	draw_star(t_game *game, int add)
{
	int	x;
	int	j;

	j = 0;
	while (++j < 4)
	{
		x = game->win.width / 2 - 325 + j * 150 + add;
		get_star(game, x, 150, 13);
	}
}

static void	handle_draw_star(t_game *game, int frames)
{
	int	modulo;

	modulo = frames % 24;
	if (modulo >= 18 && frames <= 120)
		draw_star(game, 0);
	else if (modulo >= 0 && modulo < 6 && frames <= 120)
		draw_star(game, 25);
	else if (modulo >= 6 && modulo < 12 && frames <= 120)
		draw_star(game, 50);
	else if (modulo >= 12 && modulo < 18 && frames <= 120)
		draw_star(game, 75);
}

void	cutscene(t_game *game, int frames)
{	
	draw_font(game, 0xffffff);
	if (frames == 0)
	{
		play("afplay Sound/Hit.mp3");
		sleep(2);
	}
	handle_draw_star(game, frames);
	draw(game);
	if (frames < 120)
		mlx_string_put(game->mlx, game->win.mlx_ptr, game->win.width / 2 - 80,
			game->win.height / 2 - 20, C_DOC, "AIE ma teutete ...");
	else
		mlx_string_put(game->mlx, game->win.mlx_ptr, game->win.width / 2 - 150,
			game->win.height / 2 - 20, C_DOC, "Ou suis-je ? Courage, FUYONS !");
}
