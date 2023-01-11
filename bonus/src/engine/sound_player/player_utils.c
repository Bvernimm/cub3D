/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:31:31 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 11:17:48 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_duration(int id)
{
	if (id == 0)
		return (DURATION_0);
	else if (id == 1)
		return (DURATION_1);
	return (-1);
}

char	*get_path_song(int id)
{
	if (id == 0)
		return (ft_strdup(SOUND_0));
	else if (id == 1)
		return (ft_strdup(SOUND_1));
	return (NULL);
}

/**
 * @brief Permet de créer 
 * 
 * @param game 
 */
void	init_player(t_game *game)
{
	game->player.is_play = -1;
	game->player.id_song = -1;
	game->player.end = -1;
	if (pthread_mutex_init(&(game->player.play), NULL))
		ft_error("Mutex init failed\n", game);
	game->player.is_play = 0;
	if (pthread_mutex_init(&(game->player.song), NULL))
		ft_error("Mutex init failed\n", game);
	game->player.id_song = 0;
	if (pthread_mutex_init(&(game->player.end_td), NULL))
		ft_error("Mutex init failed\n", game);
	game->player.end = 0;
	if (pthread_cond_init(&(game->player.cond_signal), NULL))
		ft_error("Cond init failed\n", game);
	game->control.is_thread = 1;
}

void	on_off_song(t_game *game)
{
	pthread_mutex_lock(&(game->player.play));
	if (game->player.is_play)
		game->player.is_play = 0;
	else if (game->player.is_play == 0)
		game->player.is_play = 1;
	pthread_mutex_unlock(&(game->player.play));
	pthread_cond_signal(&(game->player.cond_signal));
}

void	change_song(t_game *game, int id)
{
	pthread_mutex_lock(&(game->player.play));
	game->player.is_play = 0;
	pthread_mutex_unlock(&(game->player.play));
	pthread_cond_signal(&(game->player.cond_signal));
	sleep(1);
	pthread_mutex_lock(&(game->player.song));
	game->player.id_song = id;
	pthread_mutex_unlock(&(game->player.song));
	pthread_mutex_lock(&(game->player.play));
	game->player.is_play = 1;
	pthread_mutex_unlock(&(game->player.play));
	pthread_cond_signal(&(game->player.cond_signal));
}
