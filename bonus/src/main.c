/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaruell <llaruell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:57:02 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/03 08:03:57 by llaruell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	launch_game(t_game game)
{
	mlx_hook(game.win.mlx_ptr, MLX_KEY_PRESS, 1L << 0, &key_pressed, &game);
	mlx_hook(game.win.mlx_ptr, MLX_KEY_RELEASE, 1L << 1, &key_released, &game);
	mlx_hook(game.win.mlx_ptr, MLX_DESTROY_NOTIF, 0L, &exit_game, &game);
	mlx_hook(game.win.mlx_ptr, 6, 0, mouse_hook, &game);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_loop(game.mlx);
}

static	void	launch_player(t_game *game)
{
	init_player(game);
	if (pthread_create(&game->player.thread, NULL, launch_song, (void *) &game))
		ft_error("Thread failed\n", game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	parsing(argc, argv, &game);
	launch_player(&game);
	game.frames = 0;
	launch_game(game);
}
