/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:30:17 by llaruell          #+#    #+#             */
/*   Updated: 2023/01/05 11:17:57 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_end(t_game *game, int song, int moment)
{
	int	i;

	i = moment;
	pthread_mutex_lock(&(game->player.play));
	pthread_mutex_lock(&(game->player.song));
	while (i < game->player.duration
		&& game->player.is_play
		&& song == game->player.id_song)
	{
		pthread_mutex_unlock(&(game->player.song));
		pthread_mutex_unlock(&(game->player.play));
		i = wait_player(game, i);
		sleep(TIME_WAIT);
		i += TIME_WAIT;
		pthread_mutex_lock(&(game->player.play));
		pthread_mutex_lock(&(game->player.song));
	}
	pthread_mutex_unlock(&(game->player.song));
	pthread_mutex_unlock(&(game->player.play));
	return (i);
}

static char	*get_play(t_game *game, char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		k;
	int		l;

	k = ft_strlen(s1);
	l = ft_strlen(s2);
	res = (char *)malloc (sizeof(char) * (k + l + 1));
	if (!res)
		print_error(game, "Malloc Issues\n");
	i = -1;
	j = -1;
	while (++i < k)
		res[i] = s1[i];
	while (++j < l)
		res[i++] = s2[j];
	res[i] = '\0';
	free(s1);
	free(s2);
	return (res);
}

static void	play_song(t_game *game, int song)
{
	char	*str;
	int		i;

	str = get_play(game, ft_strdup(AFPLAY),
			get_path_song(game->player.id_song));
	game->player.duration = get_duration(game->player.id_song);
	pthread_mutex_unlock(&(game->player.song));
	i = 0;
	play(str);
	pthread_mutex_lock(&(game->player.play));
	while (game->player.is_play > 0 && i < game->player.duration)
	{	
		pthread_mutex_unlock(&(game->player.play));
		i = check_end(game, song, i);
		pthread_mutex_lock(&(game->player.play));
	}
	pthread_mutex_unlock(&(game->player.play));
	pthread_mutex_lock(&(game->player.play));
	if (game->player.is_play == 0)
		stop();
	pthread_mutex_unlock(&(game->player.play));
	free(str);
}

static void	waiting_play(t_game *game)
{
	pthread_mutex_lock(&(game->player.play));
	pthread_mutex_lock(&(game->player.end_td));
	while (game->player.is_play == 0 && game->player.end == 0)
	{
		pthread_mutex_unlock(&(game->player.end_td));
		pthread_mutex_unlock(&(game->player.play));
		pthread_cond_wait(&(game->player.cond_signal), &(game->player.play));
		pthread_mutex_unlock(&(game->player.play));
		pthread_mutex_lock(&(game->player.play));
		pthread_mutex_lock(&(game->player.end_td));
	}
	pthread_mutex_unlock(&(game->player.play));
	pthread_mutex_unlock(&(game->player.end_td));
}

/**
 * @brief Lance le lecteur de musique d'ambiance
 * 
 * @param arg 
 * @return void* 
 */
void	*launch_song(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	waiting_play(game);
	pthread_mutex_lock(&(game->player.end_td));
	while (game->player.end == 0)
	{
		pthread_mutex_unlock(&(game->player.end_td));
		pthread_mutex_lock(&(game->player.play));
		if (game->player.is_play)
		{
			pthread_mutex_unlock(&(game->player.play));
			pthread_mutex_lock(&(game->player.song));
			play_song(game, game->player.id_song);
		}
		pthread_mutex_unlock(&(game->player.play));
		waiting_play(game);
		pthread_mutex_lock(&(game->player.end_td));
	}
	pthread_mutex_unlock(&(game->player.end_td));
	return (NULL);
}
