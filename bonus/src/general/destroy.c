/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:52:47 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 11:13:06 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	end_thread(t_game *game)
{
	pthread_mutex_lock(&(game->player.end_td));
	game->player.end = 1;
	pthread_mutex_unlock(&(game->player.end_td));
	pthread_cond_signal(&(game->player.cond_signal));
	usleep(10);
	pthread_mutex_lock(&(game->player.play));
	game->player.is_play = 0;
	pthread_mutex_unlock(&(game->player.play));
	pthread_cond_signal(&(game->player.cond_signal));
	usleep(10);
	pthread_join(game->player.thread, NULL);
}

void	destroy_thread(t_game *game)
{
	end_thread(game);
	destroy_init_mutex(game);
	pthread_cond_destroy(&game->player.cond_signal);
}

void	destroy_init_mutex(t_game *game)
{
	if (game->player.is_play != -1)
		pthread_mutex_destroy(&(game->player.play));
	if (game->player.id_song != -1)
		pthread_mutex_destroy(&(game->player.song));
	if (game->player.end != -1)
		pthread_mutex_destroy(&(game->player.end_td));
}
