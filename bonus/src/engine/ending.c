/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:47:51 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 08:52:39 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_bad_screen(t_game *game, int x, int y)
{
	mlx_string_put(game->mlx, game->win.mlx_ptr, x + 232, y,
		C_RED, "  GAME OVER  ");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x + 232, y + 20,
		C_RED, "-------------");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 45, C_RED,
		"* --------------------------------------------------------- *");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 90, C_RED,
		"|                       You died...                         |");
	mlx_string_put(game->mlx, game->win.mlx_ptr, x, y + 135, C_RED,
		"* --------------------------------------------------------- *");
}

void	get_scared(t_game *game, int x, int y)
{
	int		height;
	int		width;
	void	*img;

	(void)x;
	(void)y;
	img = mlx_xpm_file_to_image(game->mlx, "Textures/screamer3.xpm",
			&height, &width);
	mlx_put_image_to_window(game->mlx, game->win.mlx_ptr, img, 140, 40);
}

void	bad_ending(t_game *game, int frames)
{
	int	x;
	int	y;

	game->control.endgame = 1;
	x = game->win.width / 2 - 302;
	y = game->win.height / 2 - 128;
	mlx_clear_window(game->mlx, game->win.mlx_ptr);
	if (frames == 0)
	{
		stop();
		play("afplay Sound/scream.mp3");
	}
	if (frames <= 160)
		get_scared(game, x, y);
	else
		draw_bad_screen(game, x, y);
}
