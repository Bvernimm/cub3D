/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:31:59 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 11:12:45 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Permet de convertir une durée relative en durée absolu
 * 			en ajoutant les secondes de la date actuelle
 * 
 * @param duration 
 * @return struct timespec 
 */
static struct timespec	convert_duration(int duration)
{
	struct timespec	time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time.tv_sec = now.tv_sec + (duration / 1000);
	time.tv_nsec = now.tv_usec + (1000UL * duration) * 1000UL;
	return (time);
}

/**
 * @brief Permet de vérifier si on a reçu un signal pour le lecteur
 * 
 * @param game Variable stockant les differentes infos sur le jeu
 * @param i Compteur
 * @return Compteur
 */
int	wait_player(t_game *game, int i)
{
	struct timespec	time;

	time = convert_duration(TIME_WAIT * 1000);
	if (pthread_cond_timedwait(&(game->player.cond_signal),
			&(game->player.play), &time) == 22)
	{
		pthread_mutex_lock(&(game->player.play));
		if (game->player.is_play == 2)
		{
			pthread_mutex_unlock(&(game->player.play));
			time = convert_duration(TIME_WAIT * 1000);
			while (game->player.is_play == 2
				&& pthread_cond_timedwait(&(game->player.cond_signal),
					&(game->player.play), &time) == 22)
			{
				sleep(TIME_WAIT);
				i += TIME_WAIT;
			}
		}
		pthread_mutex_unlock(&(game->player.play));
	}
	pthread_mutex_unlock(&(game->player.play));
	return (i);
}
